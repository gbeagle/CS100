# implementation of card game - Memory

import simplegui
import random

cards = range(0, 8) + range(0, 8)
exposed = [False]*16
state = 0       #num cards flipped
idx1 = 0		#first card flipped
idx2 = 0		#second card flipped
turns = 0

def new_game():
    global exposed, state, turns
    random.shuffle(cards)  
    exposed = [False]*16
    state = 0
    turns = 0
     
# define event handlers
def mouseclick(pos):
    global state, idx1, idx2, turns
    
    if state == 0:
        idx1 = pos[0] / 50
        state = 1
        exposed[idx1] = True
        
    elif state == 1:
        if exposed[pos[0] / 50] == False:
            turns += 1
            idx2 = pos[0] / 50
            exposed[idx2] = True
            state = 2
    else:
        if cards[idx1] != cards[idx2]:
            exposed[idx1] = False
            exposed[idx2] = False

        if exposed[pos[0] / 50] == False:
            idx1 = pos[0] / 50
            exposed[idx1] = True
            state = 1

# cards are logically 50x100 pixels in size    
def draw(canvas):
    label.set_text("Turns = " + str(turns))
    for i in range(len(cards)):
        pos = 50 * i
        canvas.draw_text(str(cards[i]), ((12 + pos), 75), 50, "White")  
        if exposed[i] == False:
            canvas.draw_polygon([(pos, 1), (pos + 50, 1), (pos + 50, 99), (pos, 99) ], 2, "Black", "Green")

# create frame and add a button and labels
frame = simplegui.create_frame("Memory", 800, 100)
frame.add_button("Reset", new_game)
label = frame.add_label("Label")
label.set_text("Turns = " + str(turns))

# register event handlers
frame.set_mouseclick_handler(mouseclick)
frame.set_draw_handler(draw)

# get things rolling
new_game()
frame.start()

# Always remember to review the grading rubric

# Implementation of classic arcade game Pong

import simplegui
import random

# Constants
WIDTH = 600
HEIGHT = 400       
BALL_RADIUS = 20
PAD_WIDTH = 8
PAD_HEIGHT = 80
HALF_PAD_WIDTH = PAD_WIDTH / 2
HALF_PAD_HEIGHT = PAD_HEIGHT / 2
LEFT = False
RIGHT = True

# Variables
paddle1_pos = HEIGHT / 2
paddle2_pos = HEIGHT / 2
ball_pos = [WIDTH/2, HEIGHT/2]
ball_vel = [0, 0]
paddle1_vel = 0
paddle2_vel = 0
score1 = 0
score2 = 0

#if direction is false, ball has v0 going left
def spawn_ball(direction):
    global ball_pos, ball_vel
    ball_pos = [WIDTH / 2, HEIGHT/2]
    ball_vel = [0, 0]
    x_vel = int(random.randrange(2, 4))
    if direction == False:
        x_vel = -1 * x_vel
    y_vel = int(random.randrange(3, 6))
    ball_vel = [x_vel, y_vel]
    
# define event handlers
def new_game():
    global paddle1_pos, paddle2_pos, paddle1_vel, paddle2_vel, score1, score2
    paddle1_pos = HEIGHT / 2
    paddle2_pos = HEIGHT / 2
    paddle1_vel = 0
    paddle2_vel = 0
    score1 = 0
    score2 = 0
    direction = random.choice([True, False])
    spawn_ball(direction)

def draw(canvas):
    global score1, score2, paddle1_pos, paddle2_pos, ball_pos, ball_vel, paddle1_vel, paddle2_vel
    
    # draw mid line and gutters
    canvas.draw_line([WIDTH / 2, 0],[WIDTH / 2, HEIGHT], 1, "White")
    canvas.draw_line([PAD_WIDTH, 0],[PAD_WIDTH, HEIGHT], 1, "White")
    canvas.draw_line([WIDTH - PAD_WIDTH, 0],[WIDTH - PAD_WIDTH, HEIGHT], 1, "White")
        
    # update ball
    ball_pos[0] += ball_vel[0]
    ball_pos[1] += ball_vel[1]

    if (ball_pos[1] <= BALL_RADIUS) or (ball_pos[1] >= HEIGHT - BALL_RADIUS):
        ball_vel[1] = -1 * ball_vel[1]   
        
    # draw ball
    canvas.draw_circle(ball_pos, BALL_RADIUS, 1, "White", "White")
    
    # update paddle's vertical position, keep paddle on the screen   
    paddle1_pos += paddle1_vel
    paddle2_pos += paddle2_vel
    if (paddle1_pos - HALF_PAD_HEIGHT < 0) or (paddle1_pos > HEIGHT - HALF_PAD_HEIGHT):
        paddle1_vel = 0
    if (paddle2_pos - HALF_PAD_HEIGHT < 0) or (paddle2_pos > HEIGHT - HALF_PAD_HEIGHT):
        paddle2_vel = 0
        
    # draw paddles
    canvas.draw_polygon([[0, paddle1_pos - HALF_PAD_HEIGHT],[0, paddle1_pos + HALF_PAD_HEIGHT], 
                         [PAD_WIDTH, paddle1_pos + HALF_PAD_HEIGHT], [PAD_WIDTH, paddle1_pos - HALF_PAD_HEIGHT]],  
                        1, "White", "White") #left
    
    canvas.draw_polygon([[WIDTH, paddle2_pos - HALF_PAD_HEIGHT],[WIDTH, paddle2_pos + HALF_PAD_HEIGHT], 
                         [WIDTH - PAD_WIDTH, paddle2_pos + HALF_PAD_HEIGHT], [WIDTH - PAD_WIDTH, paddle2_pos - HALF_PAD_HEIGHT]],  
                        1, "White", "White")# right
    
    # determine whether paddle and ball collide
    if (ball_pos[0] <= PAD_WIDTH + BALL_RADIUS): 
        if (ball_pos[1] <= paddle1_pos + HALF_PAD_HEIGHT) and (ball_pos[1] >= paddle1_pos - HALF_PAD_HEIGHT):
            ball_vel[0] *= -1.1
        else:
            score2 += 1
            spawn_ball(RIGHT)
        
    if (ball_pos[0] >= WIDTH - PAD_WIDTH - BALL_RADIUS):
        if (ball_pos[1] <= paddle2_pos + HALF_PAD_HEIGHT) and (ball_pos[1] >= paddle2_pos - HALF_PAD_HEIGHT):
            ball_vel[0] *= -1.1   
        else:
            score1 += 1
            spawn_ball(LEFT)
    
    # draw scores
    canvas.draw_text(str(score1), [260, 30], 30, "White")
    canvas.draw_text(str(score2), [320, 30], 30, "White")
        
def keydown(key):
    global paddle1_vel, paddle2_vel
    if key == simplegui.KEY_MAP["w"]:
        paddle1_vel = -12
    if key == simplegui.KEY_MAP["s"]:
        paddle1_vel = 12
    if key == simplegui.KEY_MAP["up"]:
        paddle2_vel = -12
    if key == simplegui.KEY_MAP["down"]:
        paddle2_vel = 12

def keyup(key):
    global paddle1_vel, paddle2_vel
    if key == simplegui.KEY_MAP["w"] or key == simplegui.KEY_MAP["s"]:
        paddle1_vel = 0
    if key == simplegui.KEY_MAP["up"] or key == simplegui.KEY_MAP["down"]:
        paddle2_vel = 0

# create frame
frame = simplegui.create_frame("Pong", WIDTH, HEIGHT)
frame.set_draw_handler(draw)
frame.set_keydown_handler(keydown)
frame.set_keyup_handler(keyup)
frame.add_button("Reset game", new_game)

# start frame
new_game()
frame.start()

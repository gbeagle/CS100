# template for "Stopwatch: The Game"

import simplegui

# define global variables
time = 0
success_stops = 0
total_stops = 0
running = False

# define helper function format that converts time
# in tenths of seconds into formatted string A:BC.D
def format(t):
    #Use modulo & division to slice up current time
    d = str(t % 10) 			     #fractional seconds
    c = str( (t / 10) % 10)		     #seconds
    b = str((t / 100) % 6)		     #tens of seconds
    a = str((t / 100) / 6)		     #minutes
    time = a + ":" + b + c + "." + d #format for timer
    return time    
    
# define event handlers for buttons; "Start", "Stop", "Reset"
def startbutton():
    timer.start()
    global running
    running = True
    
def stopbutton():
    timer.stop() 
    global time
    global total_stops
    global success_stops
    global running
    if running == True:
        total_stops+=1
        running = False
    if (time % 10 == 0):
        success_stops+=1
    
def resetbutton():
    timer.stop()
    global time
    global total_stops
    global success_stops
    global running
    time = 0
    total_stops = 0
    success_stops = 0
    running = False
    
# define event handler for timer with 0.1 sec interval
def timerhandler():
    global time
    time+=1

# define draw handler
def draw(canvas):
    global time
    global success_stops
    global total_stops
    attempts = str(success_stops) + "/" + str(total_stops)
    canvas.draw_text(format(time), [50, 100], 40, "Aqua")
    canvas.draw_text(attempts, [180, 10], 15, "Aqua")
    
# create frame
frame = simplegui.create_frame("Stopwatch", 200, 200)
timer = simplegui.create_timer(100, timerhandler)

# register event handlers
startbutton = frame.add_button("Start", startbutton)
stopbutton = frame.add_button("Stop", stopbutton)
resetbutton = frame.add_button("Reset", resetbutton)
frame.set_draw_handler(draw)

# start frame
frame.start()

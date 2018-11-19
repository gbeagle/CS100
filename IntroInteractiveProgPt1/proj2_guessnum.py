# template for "Guess the number" mini-project
# input will come from buttons and an input field
# all output for the game will be printed in the console

import simplegui
import math
import random

upper_bound = 100

# helper function to start and restart the game
def new_game():
    global secret_number
    global upper_bound
    global num_guesses
    num_guesses = int(math.ceil(math.log(upper_bound+1, 2)))
    secret_number = random.randrange(0, upper_bound)
   
def range100():
    global upper_bound 
    upper_bound = 100
    print
    print "-----New game-----"
    print "Range is " + str(upper_bound)
    new_game()

def range1000():
    global upper_bound
    upper_bound = 1000
    print
    print "-----New game-----"
    print "Range is " + str(upper_bound)
    new_game()
    
def input_guess(guess):
    print 
    global num_guesses 
    num_guesses = num_guesses-1

    print "Guess was " + guess
    guess = int(guess)
    
    if(num_guesses == 0):
        print "Out of guesses"
        print
        print "-----New game-----"
        new_game()

    elif(guess > upper_bound or guess < 0):
        print "Guess out of bounds"
    elif (guess < secret_number):
        print "Higher"
    elif (guess > secret_number):
        print "Lower"
    elif (guess == secret_number):
        print "Correct"
        print
        print "-----New game-----"
        new_game()
    
    print "Guesses remaining: " + str(num_guesses)
    
# create frame
frame = simplegui.create_frame("Guess the number", 200, 200)
frame.add_input("Guess: ", input_guess, 150)
frame.add_button("Range is [0, 100)", range100, 100)
frame.add_button("Range is [0, 1000)", range1000, 100)

# start game
print "Welcome to Guess The number! Please enter your guess."
print "Range is " + str(upper_bound)
new_game()
frame.start()


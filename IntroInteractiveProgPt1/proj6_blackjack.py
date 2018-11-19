# Mini-project #6 - Blackjack

import simplegui
import random

# load card sprite - 936x384 - source: jfitz.com
CARD_SIZE = (72, 96)
CARD_CENTER = (36, 48)
card_images = simplegui.load_image("http://storage.googleapis.com/codeskulptor-assets/cards_jfitz.png")

CARD_BACK_SIZE = (72, 96)
CARD_BACK_CENTER = (36, 48)
card_back = simplegui.load_image("http://storage.googleapis.com/codeskulptor-assets/card_jfitz_back.png")    

# initialize some useful global variables
in_play = False
outcome = ""
score = 0


# define globals for cards
SUITS = ('C', 'S', 'H', 'D')
RANKS = ('A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K')
VALUES = {'A':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'T':10, 'J':10, 'Q':10, 'K':10}


# define card class
class Card:
    def __init__(self, suit, rank):
        if (suit in SUITS) and (rank in RANKS):
            self.suit = suit
            self.rank = rank
        else:
            self.suit = None
            self.rank = None
            print "Invalid card: ", suit, rank

    def __str__(self):
        return self.suit + self.rank

    def get_suit(self):
        return self.suit

    def get_rank(self):
        return self.rank

    def draw(self, canvas, pos):
        card_loc = (CARD_CENTER[0] + CARD_SIZE[0] * RANKS.index(self.rank), 
                    CARD_CENTER[1] + CARD_SIZE[1] * SUITS.index(self.suit))
        canvas.draw_image(card_images, card_loc, CARD_SIZE, [pos[0] + CARD_CENTER[0], pos[1] + CARD_CENTER[1]], CARD_SIZE)
        
# define hand class
class Hand:
    def __init__(self):
        self.hand = []

    def __str__(self):
        cards = ""
        for c in self.hand:
            cards +=  " " + c.get_suit() + c.get_rank()
        return "Hand contains" + cards

    def add_card(self, card):
        self.hand.append(card)

    def get_value(self):
        hand_val = 0
        aces = False
        for card in self.hand:
            if card.get_rank() == "A":
                aces = True
            hand_val += VALUES[card.get_rank()]
        if aces == False:
            return hand_val
        else:
            if hand_val + 10 <= 21:
                return hand_val + 10
            else:
                return hand_val  
            
    def draw(self, canvas, pos):
        for c in self.hand:
            c.draw(canvas, pos)
            pos[0] += 100
 
        
# define deck class 
class Deck:
    def __init__(self):
        self.deck = [Card(suit, rank) for suit in SUITS for rank in RANKS]

    def shuffle(self):
        random.shuffle(self.deck)

    def deal_card(self):
        return self.deck.pop()
    
    def __str__(self):
        cards = ""
        for c in self.deck:
            cards +=  " " + c.get_suit() + c.get_rank()
        return "Deck contains" + cards


#define event handlers for buttons
def deal():
    global outcome, in_play, deck, player_hand, dealer_hand, dealer_val, score
    outcome = ""
    deck = Deck()
    player_hand = Hand()
    dealer_hand = Hand()
    
    deck.shuffle()
    player_hand.add_card(deck.deal_card())
    dealer_hand.add_card(deck.deal_card())
    player_hand.add_card(deck.deal_card())
    dealer_hand.add_card(deck.deal_card())        
    if in_play == True:
        outcome = "Player loses point."
        in_play = False
        score -= 1 
    in_play = True


def hit():
    global in_play, player_hand, deck, score, outcome
    
    if in_play == True:
        if player_hand.get_value() <= 21:
            player_hand.add_card(deck.deal_card())    
        if player_hand.get_value() > 21:
            outcome = "Player busts! Try again?"
            score -= 1
            in_play = False


def stand():
    global player_hand, deck, score, in_play, outcome
    
    if player_hand.get_value() > 21:
        outcome = "Player busted. Try again?"
    if in_play == True:
        while dealer_hand.get_value() <= 17:
            dealer_hand.add_card(deck.deal_card()) 
        in_play = False
        if dealer_hand.get_value() > 21:
            outcome = "Dealer busts. Player wins!"
            score += 1
        elif player_hand.get_value() <= dealer_hand.get_value():
            outcome = "Dealer wins! Try again?"
            score -= 1
        else:
            outcome = "Player wins! Try again?"
            score += 1


# draw handler    
def draw(canvas):
    global outcome, score
    
    canvas.draw_text("BLACKJACK", [450, 30], 20, "Yellow")
    canvas.draw_text("Score: " + str(score), [450, 60], 20, "Yellow")

    dealer_hand.draw(canvas, [50, 172])
    canvas.draw_text("Dealer: " + outcome, [50, 155], 30, "Yellow")
    
    player_hand.draw(canvas, [50, 452])
    canvas.draw_text("Player: ", [50, 435], 30, "Yellow")
    canvas.draw_text("Value: " + str(player_hand.get_value()), [50, 575], 20, "Yellow")
    
    if in_play == True:
        canvas.draw_text("Hit or stand?", [150, 435], 30, "Yellow")
        canvas.draw_text("Value: ??", [50, 290], 20, "Yellow")
        canvas.draw_image(card_back, list(CARD_BACK_CENTER), CARD_BACK_SIZE, 
                          [50 + CARD_BACK_CENTER[0], 172 + CARD_BACK_CENTER[1]], CARD_BACK_SIZE)
    elif in_play == False:
        canvas.draw_text("Value: " + str(dealer_hand.get_value()), [50, 290], 20, "Yellow")
        canvas.draw_text("New deal?", [150, 435], 30, "Yellow")

        
# initialization frame
frame = simplegui.create_frame("Blackjack", 600, 600)
frame.set_canvas_background("Green")

#create buttons and canvas callback
frame.add_button("Deal", deal, 200)
frame.add_button("Hit",  hit, 200)
frame.add_button("Stand", stand, 200)
frame.set_draw_handler(draw)

# get things rolling
deal()
frame.start()


# remember to review the gradic rubric

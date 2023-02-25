# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Ilan Sela
#              	Dave Wright
#              	Jordan Rivas
#              	Robert Stacks
# Section:      501
# Assignment: 	Game Plan
# Date:         28 November 2022

import turtle
import random

def origin():
    t.pu()
    t.setpos(0,100)
    t.pd()

def stand():
    origin()
    t.seth(180)
    t.pu()
    t.forward(120)
    t.lt(90)
    t.forward(200)
    t.rt(90)
    t.forward(30)
    t.rt(180)
    t.pd()
    t.forward(60)
    t.pu()
    t.backward(30)
    t.lt(90)
    t.pd()
    t.forward(340)
    t.rt(90)
    t.forward(120)

def head():
    origin()
    t.seth(90) #pen faces up
    t.pu() #lift pen
    t.forward(30) 
    t.pd() #pen down
    t.rt(90) #rotates back
    t.circle(50)

def torso():
    origin()
    t.left(90)
    t.pu()
    t.forward(30)
    t.pd()
    t.left(180)
    t.forward(200)
    t.left(90) #reset pointer

def right_arm():
    origin()
    t.pu()
    t.right(90)
    t.forward(15)
    t.pd()
    t.left(45)
    t.forward(70)
    t.left(45) #reset pointer

def left_arm():
    origin()
    t.pu()
    t.right(90)
    t.forward(15)
    t.pd()
    t.right(45)
    t.forward(70)
    t.left(135) #reset pointer

def right_leg():
    origin()
    t.pu()
    t.right(90)
    t.forward(170)
    t.pd()
    t.left(45)
    t.forward(70)
    t.left(45) #reset pointer

def left_leg():
    origin()
    t.pu()
    t.right(90)
    t.forward(170)
    t.pd()
    t.right(45)
    t.forward(70)
    t.left(135) #reset pointer
    
def display_rules():
    display_rule= '''    1. Players try to figure out an unknown word by guessing letters. If too many letters which do not appear in the word are guesses, the player is hanged and (loses).
    2. The game will first display a gallow. As letters in the word are guessed, they will be written at the corresponding positions.
    3. If a letter not in the word is guessed, the program will draw a picture of a person on the gallow–one part for each incorrect letter guess. The person is drawn in 6 parts.
    4. A word bank of incorrect guessed letters will be kept and shown at times to remind the player'''
    print(f'HANGMAN RULES:\n{display_rule}\n')
    print('You are playing hang-man with a 5 letter word')


def word_pick():
    '''Function word_pick reads a random word from file 5_letter_words.txt and uses it as the correct word for current hangman game. The function returns a single word.'''
    myfile = open('5_letter_words.txt', 'r')
    all_lines = myfile.read().splitlines()
    random_word = random.choice(all_lines).strip()
    myfile.close()
    return random_word

def correct_output(guess, random_word):
    '''Function correct_output is performed when the letter guessed by the user is found in the word they are trying to guess. The function displays where the letter falls in the word and provides blank spots where letters have not been guessed. Correct_output taking in parameters of the user guess and the random word and prints out statements telling the user that they have guessed correctly and displays the correct letters that have been guessed.'''
    correct_letters.append(guess)
    print('You\'ve guessed correctly!')
    print('Word is: ', end = '')
    for i in random_word:
        counter = 0
        for j in correct_letters:
            if j == i:
                print(f'{j} ', end = '')
                counter+=1
        if counter == 0:
            print('_ ', end = '')
    print() #new line

def repeated_output(guess, guessed):
    '''Function repeated_output lets the user know that they have guessed a letter that they have already guessed. Repeated_output takes in a parameter of the letters guessed by the user and current guess. This function will tell the user that the guess they made was a repeat.'''
    if len(guessed) == 0:
        print(f'You\'ve already guessed {guess}')
    else:
        print('Repeated letter.\nYou\'ve incorrectly guessed: ', end = '')
        for i in range(len(guessed)):
            if i != len(guessed)-1:
                print(f'{guessed[i]}, ', end = '')
            else:
                print(guessed[i])

def wrong_output(guess, guessed):
    guessed_letters.append(guess)
    print(f'{guess} is not in the word')
    if len(guessed_letters) != 0:
        print('You\'ve incorrectly guessed: ', end = '')
        for i in range(len(guessed)):
            if i != len(guessed)-1:
                print(f'{guessed[i]}, ', end = '')
            else:
                print(guessed[i])

def check_input(guess, random_word, guessed, wrong):
    if guess in random_word and not(guess in guessed or guess in correct_letters): #correct
        correct_output(guess, random_word)
        wrong-=1
    elif guess in guessed or guess in correct_letters: #already guessed
        repeated_output(guess, guessed)
        wrong-=1
    else: #not already guessed nor in word
        wrong_output(guess, guessed)
    
    return wrong

#set up turtle window w/ stand
t = turtle.Turtle() # Reference turtle as t
turtle.title("Hangman")
t.hideturtle()
t.speed(0)
stand()

#declare lists and variable
guessed_letters = []
correct_letters = []
wrong = 0

#pick random word
random_word = word_pick()

#dictionary used to draw stickman
countdict = {1:head,2:torso,3:right_arm,4:left_arm,5:right_leg,6:left_leg}
valid = True

#display rules
display_rules()

#display options for user
print('Options for things you can do:')
print('- When prompted, you can guess any letter, but not numbers or symbols')
print('- If you wish to end the game early, type "stop" when prompted for your next guess')

while valid:
    print('-------------------------------------------------')
    
    #get user input for a letter
    user_input = input('Guess a letter: ').upper()

    #if input is int or a string (not char) loop again for reinput
    try:
        if user_input == "STOP":
            valid = False
            print(f"Ending game. The word was: {random_word}")
            break
        elif len(user_input) > 1:
            pass        
        else:
            int(user_input)
        print('Bad input! Please retry.')
    except:
        print()
        #assume that guess is wrong
        wrong+=1
    
        #check the input and see if was wrong, repeated, or correct
        wrong = check_input(user_input, random_word, guessed_letters, wrong)
    
        #if wrong, call the corresponding stick
        if wrong !=0:
            countdict[wrong]()

        #if wrong is 6, you have used all guesses
        if wrong == 6:
            print('\nYou lost :(\nThe correct word was: ', end ='')
            print(random_word)
            valid = False

        #if you have 5 letters that are right, you have guessed the word
        if len(correct_letters) == 5:
            print('You did it!')
            valid = False

#keep turtle from disappearing 
turtle.done()

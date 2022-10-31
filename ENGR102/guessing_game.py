# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 3 challenge
# Date:         7 September 2022
secretnum = 26
def guess_input():
    valid = True
    print('What is your guess? ', end='')
    while valid:
        try:
            x = int(input())
            valid = False

        except:
            print('Bad input! Try again: ', end = '')
    return x

def range_validate(x):
    if x > secretnum:
        print('Too high!')
        return 1
    elif x < secretnum:
        print('Too low!')
        return 1
    elif x == secretnum:
        print('You guessed it! It took you 3 guesses.')
        return 0


value = range_validate(guess_input())
while value != 0:
    value = range_validate(guess_input())
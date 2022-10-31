# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 3 challenge
# Date:         7 September 2022
secretnum = 26
print('Guess the secret number! Hint: it\'s an integer between 1 and 100...')
#function to retrieve input
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

#function to check if input is guessed
def range_validate(x, count):
    if x > secretnum:
        print('Too high!')
        return 1
    elif x < secretnum:
        print('Too low!')
        return 1
    elif x == secretnum:
        count+=1
        print(f'You guessed it! It took you {count} guesses.')
        return 0

#counter and run functions
count = 1
value = range_validate(guess_input(), count)
#loop until correct guess
while value != 0:
    value = range_validate(guess_input(), count)
    count+=1
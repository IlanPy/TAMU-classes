# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 6 Individual #2
# Date:         28 September 2022

#input
print(f'Enter a positive integer: ', end='')
num = int(input())
count = 0
print(f'The Juggler sequence starting at {num} is:\n{num}', end ='')

#while loop
while num!=1:
    if num%2!=0:
        num=int(num**(3/2))
    elif num%2==0:
        num=int(num**(1/2))
    count+=1

    #sequence print statement
    print(f', {num}', end =' ')
    
#final output
print(f'\nIt took {count} iterations to reach 1')
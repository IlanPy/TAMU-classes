# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 6 Individual #2
# Date:         24 August 2022

print(f'Enter a positive integer: ', end='')
num = int(input())
count = 0
print(f'{num}, ', end ='')
while num!=1:
    if num%2!=0:
        num=int(num**(3/2))
    elif num%2==0:
        num=int(num**(1/2))
    count+=1

    if num == 1:
        print(f'{num}', end =' ')
    else:
        print(f'{num},', end =' ')
    

print(f'\nIt took {count} iterations to reach 1')
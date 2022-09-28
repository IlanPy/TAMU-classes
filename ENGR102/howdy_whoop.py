# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 6 Infividual
# Date:         24 August 2022

print(f'Enter an integer: ', end='')
num1 = int(input())
print(f'Enter another integer: ', end='')
num2 = int(input())

for i in range(1,101):
    if(i%num1==0):
        print(f'Howdy')
    elif(i%num2==0):
        print(f'Whoop')
    else:
        print(i)
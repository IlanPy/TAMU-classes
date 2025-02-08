# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 6 Infividual
# Date:         24 August 2022

#input
print(f'Enter an integer: ', end='')
num1 = int(input())
print(f'Enter another integer: ', end='')
num2 = int(input())

#for loop testing values
for i in range(1,101):
    #first
    if(i%num1==0 and i%num2!=0):
        print(f'Howdy')

    #second
    elif(i%num2==0 and i%num1!=0):
        print(f'Whoop')

    #third
    elif(i%num1==0 and i%num2==0):
        print(f'Howdy Whoop')

    #else
    else:
        print(i)
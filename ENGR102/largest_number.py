# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 1a
# Date:         24 August 2022

#print statements and inputs
print(f"Enter number 1: ", end = "")
x=float(input())
print(f"Enter number 2: ", end = "")
y=float(input())
print(f"Enter number 3: ", end = "")
z=float(input())

#Determining largest num
if(x<y):
    if(y<z):
        print(f"The largest number is {z}")
    else:
        print(f"The largest number is {y}")
else:
    if(x<z):
        print(f"The largest number is {z}")
    else:
        print(f"The largest number is {x}")
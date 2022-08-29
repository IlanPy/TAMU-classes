# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 1c
# Date:         24 August 2022
from math import *

print("This shows the evaluation of (x^2-1)/(x-1) evaluated close to x=1")
print("My guess is 2")

#loops through 1.1 to 1.00000001

i=1.1
x=1

while(x<=8):
    print((i**(2)-1)/(i-1))
    i=(i-1)*0.1+1
    x+=1

print()
print("My guess was a little off")
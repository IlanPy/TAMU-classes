# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 3 challenge
# Date:         7 September 2022

from math import *

print("Please enter the number of digits of precision for e: ", end="")
input = int(input())

#output string
print(f"The value of e to {input} digits is: {e:.{input}f}")
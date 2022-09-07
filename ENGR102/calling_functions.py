# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 3 (ind)
# Date:         7 September 2022

from math import *
def printresult(shape, side, area):
    '''Print the result of the calculation'''
    print(f'A {shape} with side {side:.2f} has area {area:.3f}')
# example function call:
# printresult(<string of shape name>, <float of side>, <float of area>)
# printresult('square', 2.236, 5)
# Your code goes here

print("Please enter the side length: ", end = "")
input = float(input())
triangle = (1/4)*(input**2)*sqrt(3)
printresult("triangle", input, triangle)
square = input*input
printresult("square", input, square)
pentagon = (1/4)*sqrt(5*(5+2*sqrt(5)))*(input**2)
printresult("pentagon", input, pentagon)
dodecagon = 3*(input**2)*(2+sqrt(3))
printresult("dodecagon", input, dodecagon)
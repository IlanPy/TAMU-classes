# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 6: Activity #1
# Date:         26 September 2022

from math import *

#inputs
print(f'Enter the side length in meters: ', end = '')
x = float(input())
print(f'Enter the number of layers: ', end = '')
layers = int(input())

#initalize area
area = 0

#calculate top area
top = x*layers
top = (sqrt(3)/4)*(top**2)

#area of sides
n = layers
a = (x**2)*3
d = (x**2)*3
area = (n*((2*a+(n-1)*d)))/2

#calculation and print
total = top + area
print(f'You need {total:.2f} m^2 of gold foil to cover the pyramid')

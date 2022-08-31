# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 2 (team)
# Date:         24 August 2022

from math import *

x1 = 10
y1 = 2026
x2 = 55
y2 = 23026

time = 25

y=y1+(((time-x1)*(y2-y1))/(x2-x1))

print("Part 1:", "For t = 25 minutes, the position p =", y, "kilometers")

#Part2

time = 300
c = 2*pi*6745

y=y1+(((time-x1)*(y2-y1))/(x2-x1))

if y>c:
    print("Part 2:", "For t = 300 minutes, the position p =", y%c, "kilometers")
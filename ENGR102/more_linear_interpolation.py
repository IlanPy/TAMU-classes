# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 2 (ind-p2)
# Date:         24 August 2022

from math import *

x0 = 8
y0 = 6
z0 = 7
x2 = -5
y2 = 30
z2 = 9

time = 30
tstart = 30
tend = 60
time1 = 12
time2 = 85


#loop1
x1=x0+(((time-time1)*(x2-x0))/(time2-time1))
y1=y0+(((time-time1)*(y2-y0))/(time2-time1))
z1=z0+(((time-time1)*(z2-z0))/(time2-time1))

print("At time", time, "seconds:")
print("x1 =", x1, "m")
print("y1 =", y1, "m")
print("z1 =", z1, "m")
print("-----------------------")

#loop2
time = tstart + (tend - tstart)/4

x1=x0+(((time-time1)*(x2-x0))/(time2-time1))
y1=y0+(((time-time1)*(y2-y0))/(time2-time1))
z1=z0+(((time-time1)*(z2-z0))/(time2-time1))

print("At time", time, "seconds:")
print("x2 =", x1, "m")
print("y2 =", y1, "m")
print("z2 =", z1, "m")
print("-----------------------")

#loop3
time = tstart + 2*(tend - tstart)/4

x1=x0+(((time-time1)*(x2-x0))/(time2-time1))
y1=y0+(((time-time1)*(y2-y0))/(time2-time1))
z1=z0+(((time-time1)*(z2-z0))/(time2-time1))

print("At time", time, "seconds:")
print("x3 =", x1, "m")
print("y3 =", y1, "m")
print("z3 =", z1, "m")
print("-----------------------")

#loop4
time = tstart + 3*(tend - tstart)/4

x1=x0+(((time-time1)*(x2-x0))/(time2-time1))
y1=y0+(((time-time1)*(y2-y0))/(time2-time1))
z1=z0+(((time-time1)*(z2-z0))/(time2-time1))

print("At time", time, "seconds:")
print("x4 =", x1, "m")
print("y4 =", y1, "m")
print("z4 =", z1, "m")
print("-----------------------")

#loop4
time = tend

x1=x0+(((time-time1)*(x2-x0))/(time2-time1))
y1=y0+(((time-time1)*(y2-y0))/(time2-time1))
z1=z0+(((time-time1)*(z2-z0))/(time2-time1))

print("At time", time, "seconds:")
print("x5 =", x1, "m")
print("y5 =", y1, "m")
print("z5 =", z1, "m")


# By submitting this assignment, I agree to the following:
#  "Aggies do not lie, cheat, or steal, or tolerate those who do."
#  "I have not given or received any unauthorized aid on this assignment."
#
# Names:        	Ilan Sela
# Section:      	501
# Assignment:   	Boiling Curve Planning
# Date:         	21 September 2022
from math import *

#variables
ax = 1.3
ay = 1000
bx = 5
by = 7000
cx = 30
cy = 1.5*(10**6)
dx = 120
dy = 2.5*(10**4)
ex = 1200
ey = 1.5*(10**6)
y = 0
m=0

#input
print(f'Enter the excess temperature: ', end ='')
x = float(input())

#conditionals
if(x<ax):
    print('Surface heat flux is not available')
elif(x<bx):
    m=log10(by/ay)/log10(bx/ax)
    y=ay*(x/ax)**m
elif(x<cx):
    m=log10(cy/by)/log10(cx/bx)
    y=by*(x/bx)**m
elif(x<cx):
    m=log10(dy/cy)/log10(dx/cx)
    y =cy*(x/cx)**m
elif(x<dx):
    m=log10(ey/dy)/log10(ex/dx)
    y=dy*(x/dx)**m
elif(x==ex):
    y=1.5*(10**6)
elif(ex<x):
    print('Surface heat flux is not available')

#output
if(y!=0):
    print(f'The surface heat flux is approximately {int(y)} W/m^2')
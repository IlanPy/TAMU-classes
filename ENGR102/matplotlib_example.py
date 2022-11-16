# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 12b
# Date:         16 November 2022

# As a team, we have gone through all required sections of the  
# tutorial, and each team member understands the material 
import matplotlib.pyplot as plt
import numpy as np
from math import pi

#first plot
x = np.linspace(-2,2)

plt.figure()

plt.plot(x,(1/(4*2))*x**2, 'r', label ='f=2', linewidth = 2.0)
plt.plot(x,(1/(4*6))*x**2, 'b', label ='f=6', linewidth = 6.0)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Parabola plots with varying focal length')
plt.legend()
plt.show()

#second plot

x= np.linspace(-4,4, num =25)

plt.figure()

plt.plot(x, 2*(x**3) + 3*(x**2) -11*x -6, '*', color='#FFFF14', ms = 10.0, mec = 'k')
plt.xlabel('x values')
plt.ylabel('y values')
plt.title('Plot of cubic polynomial')
plt.show()

#third plot
x= np.linspace(-2*pi,2*pi)

plt.figure()

plt.subplot(211)
plt.plot(x, np.cos(x), color = '#800000', label = 'cos(x)')
plt.ylabel('y=cos(x)')
plt.legend(loc = 'lower right')
plt.title('Plot of cos(x) and sin(x)')
plt.subplot(212)
plt.plot(x, np.sin(x), color = 'tab:gray', label = 'sin(x)')
plt.ylabel('y=sin(x)')
plt.xlabel('x')
plt.legend()
plt.show()

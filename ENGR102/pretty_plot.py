# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 12a Indv
# Date:         14 November 2022



import numpy as np
import matplotlib.pyplot as plt

plt.figure()

#create matrix and first vector
matrixA = np.array([1.01,0.09,-0.09,1.01]).reshape(2,2)
pointB = np.array([0,1])

#loop through 200
for i in range(200):
    #multiply matrix and vector
    y= matrixA @ pointB
    #dot can be expressed with . or o
    plt.plot(y[0], y[1], '.')
    pointB = y

#label
plt.ylabel('y-axis')
plt.xlabel('x-axis')
plt.title('Spiral Traced by Points')
plt.show()
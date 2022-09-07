# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 3 (ind)
# Date:         7 September 2022
from math import *

#Calculate net force using Newtons Second Law with mass 3 kg and acceleration 5.5 m/s^2.
print("This program calculates the applies force given mass and acceleration")
print("Please enter the distance (nm): ", end = "")
mass = float(input())
print("Please enter the acceleration (m/s^2): ", end = "")
acc = float(input())

force = mass*acc

print("Force is", force, "N")


#Calculate the wavelength of x-rays scattering from a crystal lattice with a distance between 
#crystal layers of 0.025 nm, scattering angle of 25 degrees, and first order diffraction using Bragg’s Law .
print("This program calculates the wavelength given distance and angle")
print("Please enter the distance (nm): ", end = "")
d = float(input())
print("Please enter the angle (degrees): ", end = "")
angle = (float(input())*pi)/180
wavelength = 2*d*sin(angle)
print("Wavelength is", wavelength, "nm")

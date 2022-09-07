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
print("This program calculates the applied force given mass and acceleration")
print("Please enter the mass (kg): ", end = "")
mass = float(input())
print("Please enter the acceleration (m/s^2): ", end = "")
acc = float(input())

force = mass*acc

print("Force is", force, "N")


#Calculate the wavelength of x-rays scattering from a crystal lattice with a distance between 
#crystal layers of 0.025 nm, scattering angle of 25 degrees, and first order diffraction using Bragg’s Law .
print("\nThis program calculates the wavelength given distance and angle")
print("Please enter the distance (nm): ", end = "")
d = float(input())
print("Please enter the angle (degrees): ", end = "")
angle = (float(input())*pi)/180
wavelength = 2*d*sin(angle)
print(f'Wavelength is, {wavelength:.4}, "nm')


#Calculate how much Radon-222 is left after 3 days of radioactive decay given an initial amount 
#of 5 g and a half-life of 3.8 days using the equation of radioactive decay.
print("\nThis program calculates how much Radon-222 is left given time and initial amount")
print("Please enter the time (days): ", end = "")
half_life = float(input())/2
print("Please enter the initial amount (g): ", end = "")
mass = float(input())
radon_222 = mass*2**(-3/half_life)
print("Radon-222 left is", radon_222, "g")


#Calculate the pressure of 5 moles of an ideal gas with a volume of 0.25 m^3, and temperature of 
#415 K using the Ideal Gas Law
print("\nThis program calculates the pressure given moles, volume, and temperature")
print("Please enter the number of moles: ", end="")
moles = float(input())
print("Please enter the volume (m^3): ", end ="")
volume = float(input())
print("Please enter the temperature (K): ", end="")
temp = float(input())
pressure = (temp*moles*8.314)/(1000*volume)
print("Pressure is", pressure,"kPa")
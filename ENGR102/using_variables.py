# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 2 (ind)
# Date:         24 August 2022
from math import *

mass = 3
acc = 5.5
force = mass*acc

#Calculate net force using Newtons Second Law with mass 3 kg and acceleration 5.5 m/s^2.
print("Force is", force, "N")

d = 0.025
angle = (5*pi)/36
wavelength = 2*d*sin(angle)

#Calculate the wavelength of x-rays scattering from a crystal lattice with a distance between 
#crystal layers of 0.025 nm, scattering angle of 25 degrees, and first order diffraction using Bragg’s Law .
print("Wavelength is", wavelength, "nm")

mass = 5
half_life = 3.8
radon_222 = mass*2**(-3/half_life)

#Calculate how much Radon-222 is left after 3 days of radioactive decay given an initial amount 
#of 5 g and a half-life of 3.8 days using the equation of radioactive decay.
print("Radon-222 left is", radon_222, "g")

volume = 0.25
temp = 415
pressure = (temp*5*8.314)/(1000*volume)

#Calculate the pressure of 5 moles of an ideal gas with a volume of 0.25 m^3, and temperature of 
#415 K using the Ideal Gas Law
print("Pressure is", pressure,"kPa")
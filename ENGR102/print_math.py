# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 1b
# Date:         24 August 2022
from math import *

#Calculate net force using Newtons Second Law with mass 3 kg and acceleration 5.5 m/s^2.
print("Force is", 3*5.5, "N")

#Calculate the wavelength of x-rays scattering from a crystal lattice with a distance between 
#crystal layers of 0.025 nm, scattering angle of 25 degrees, and first order diffraction using Bragg’s Law .
print("Wavelength is", 2*0.025*sin((5*pi)/36), "nm")

#Calculate how much Radon-222 is left after 3 days of radioactive decay given an initial amount 
#of 5 g and a half-life of 3.8 days using the equation of radioactive decay.
print("Radon-222 left is", 5*2**(-3/3.8), "g")

#Calculate the pressure of 5 moles of an ideal gas with a volume of 0.25 m^3, and temperature of 
#415 K using the Ideal Gas Law
print("Pressure is", (415*5*8.314)/(1000*0.25),"kPa")
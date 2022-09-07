# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Ilan Sela
#               Dave Wright
#               Jordan Rivas
#               Robert Stacks
# Section:      501
# Assignment:   Lab 1c-a
# Date:         7 September 2022
#


#conversions
print("Please enter the quantity to be converted: ", end = "")
value = float(input())
newtons = value*4.45
print(f'{value:.2f} pounds force is equivalent to {newtons:.2f} Newtons')
feet = value*3.28
print(f'{value:.2f} meters is equivalent to {feet:.2f} feet')
kilopascals = value*101.325
print(f'{value:.2f} atmospheres is equivalent to {kilopascals:.2f} kilopascals')
btu = value*3.41
print(f'{value:.2f} watts is equivalent to {btu:.2f} BTU per hour')
gallons = value*15.85
print(f'{value:.2f} liters per second is equivalent to {gallons:.2f} US gallons per minute')
far = value*1.8+32
print(f'{value:.2f} degrees Celsius is equivalent to {far:.2f} degrees Fahrenheit')
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
print(f'{value:.3} pounds force is equivalent to {newtons:.3} Newtons')
feet = value*3.28
print(f'{value:.3} meters is equivalent to {feet:.3} feet')
kilopascals = value*101.33
print(f'{value:.3} atmospheres is equivalent to {kilopascals:.3} kilopascals')
btu = value*3.41
print(f'{value:.3} watts is equivalent to {btu:.3} BTU per hour')
gallons = value*15.85
print(f'{value:.3} liters per second is equivalent to {gallons:.3} US gallons per minute')
far = value*1.8+32
print(f'{value:.3} celsius is equivalent to {far:.3} fahrenheit')
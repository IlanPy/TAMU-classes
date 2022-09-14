# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 4: Activity #3 Boolean expressions - team
# Date:         14 September 2022

############ Part A ############ 
from operator import truediv


print("Enter True or False for a: ", end="")
a = input()
print("Enter True or False for b: ", end="")
b = input()
print("Enter True or False for c: ", end="")
c = input()

if (a=="t" or a=="T" or a=="True"):
    a = True
elif (a=="f" or a=="F" or a=="False"):
    a = False

if (c=="t" or c=="T" or c=="True"):
    c = True
elif (c=="f" or c=="F" or c=="False"):
    c = False

if (b=="t" or b=="T" or b=="True"):
    b = True
elif (b=="f" or b=="F" or b=="False"):
    b = False

############ Part B ############ 
one = a and b and c
print(f"a and b and c: {one}")
two = a or b or c
print(f"a or b or c: {two}")

############ Part C ############ 
xor = (a or b) and not(a and b)
print(f"XOR: {xor}")

odd2 = (a and b and c) or ((a and not(b) and not(c)) or (not(a) and not(c) and b) or (not(b) and c and not(a)))
print(f"Odd number: {odd2}")

############ Part D ############ 
complex1 = (not (a and not b) or (not c and b)) and (not b) or (not a and b and not c) or (a and not b) 
complex2 = (not ((b or not c) and (not a or not c))) or (not (c or not (b and c))) or (a and not c) and (not a or (a and b 
and c) or (a and ((b and not c) or (not b)))) 
print(complex1)
simple1 = (not(a and b and c)) and (a or b and c) and (a and b or c)
print(simple1)
'''
if a and b and c = true: false
if a and b = false and c = true: true
if a and c = false and b = true: true
if b and c = false and a = true: true
if a and b = true and c = false: false
if a and c = true and b = false: true
if b and c = true and a = false: false
if a and b and c = false: true
'''
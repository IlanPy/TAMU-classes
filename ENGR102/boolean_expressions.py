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
print(f"Enter True or False for a: ", end="")
a = input()
print(f"Enter True or False for b: ", end="")
b = input()
print(f"Enter True or False for c: ", end="")
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
    a = True
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
odd3 = (a and not(b) and not(c))
odd4 = (not(a) and not(c) and b)
odd5 = (not(a) and not(b) and c)
odd6 = (a and b and c)
print(f"Odd number: {odd2}")
print(odd3, odd4, odd5, odd6)
print(False and True and True)
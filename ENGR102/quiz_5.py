#q.22 tech has '\n' at end but other boxes that ask for output do not allow to

# include \n even when needed

#import math

import math

def is_triangle(a,b,c):

    # assume it does not make a triangle

    valid = False

    #condition to see if it DOES make a triangle

    if (a < b+c) and (b < a+c) and (c < a+b):

        valid = True

    return valid

def perimeter_and_area(a,b,c):

    #perimeter is perimeter and s is half

    perimeter = a+b+c

    s = perimeter/2

    area = math.sqrt(s*(s-a)*(s-b)*(s-c))

    return perimeter, area

#main

try:

    #take input and create list of sides

    sides = input('Enter side lengths of a triangle: ').split()

    #unpack list and convert to float

    side1, side2, side3 = float(sides[0]), float(sides[1]), float(sides[2])

    #check if sides form a triangle

    if is_triangle(side1, side2, side3):

        #if they do, unpack its perimeter and area

        per, ar = perimeter_and_area(side1,side2,side3)

        #print

        print(f'Perimeter: {per} units\nArea: {ar} units^2')

    #if not triangle

    else:

        print('Not a triangle')

#if invalid input (didnt let convert to float)

except:

    print('Invalid input')
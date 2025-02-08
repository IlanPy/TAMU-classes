# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 3 challenge
# Date:         7 September 2022

from math import sqrt
root1=0
print(f'Please enter the coefficient A: ', end = '')
a=float(input())
print(f'Please enter the coefficient B: ', end = '')
b=float(input())
print(f'Please enter the coefficient C: ', end = '')
c=float(input())

#loops
det = (b**2-(4*a*c))
if(det<0):
    root1 = (-b)/(2*a)
    complexnum = sqrt(abs(det))/2*a
    print(f'The roots are x = {root1} + {complexnum}i and x = {root1} - {complexnum}i')
elif (a==0):
    if((b==0 and a==0 and c!=0) or b==0):
        print(f'You entered an invalid combination of coefficients!')
    else:
        root1 = -c/b
        print(f'The root is x = {root1}')
elif (a!=0):
    root1 = ((-b+sqrt(b**2-(4*a*c)))/2*a)
    root2 = ((-b-sqrt(b**2-(4*a*c)))/2*a)
    if(root1!=root2):
        if(root1>root2):
            print(f'The roots are x = {root1} and x = {root2}')
        else:
           print(f'The roots are x = {root2} and x = {root1}') 
    else:
        print(f'The root is x = {root1}')

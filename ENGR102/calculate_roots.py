from math import sqrt
root1=0
print(f'Please enter the coefficient A: ', end = '')
a=float(input())
print(f'Please enter the coefficient B: ', end = '')
b=float(input())
print(f'Please enter the coefficient C: ', end = '')
c=float(input())

det = (b**2-(4*a*c))
if(det<0):
    root1 = (-b)/(2*a)
    complexnum = sqrt(abs(det))/2*a
    print(f'The root is x = {root1} + {complexnum}i and x = {root1} - {complexnum}i')
elif (a==0):
    root1 = -b/c
    if(b==0 and a==0 and c!=0):
        print(f'c has to equal zero if both a and b are.')
    else:
        print(f'The root is x = {root1}')
elif (a!=0):
    root1 = ((-b+sqrt(b**2-(4*a*c)))/2*a)
    root2 = ((-b-sqrt(b**2-(4*a*c)))/2*a)
    if(root1!=root2):
        if(root1>root2):
            print(f'The root is x = {root1} and x = {root2}')
        else:
           print(f'The root is x = {root2} and x = {root1}') 
    else:
        print(f'The root is x = {root1}')

# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 7b
# Date:         5 October 2022
from math import *

print('Enter the elements for vector A: ', end='')
strA = input()
lA = strA.split(" ")
print('Enter the elements for vector B: ', end='')
strB = input()
lB = strB.split(" ")
listA=[]
listB=[]
magA = 0
magB = 0
dotprod = 0
product = []
listAdd = []
listSub = []

#creates a float list and calculates magnitude
for i in lA:
    listA.append(float(i))

for i in listA:
    magA+=(i**2)
magA=sqrt(magA)

for i in lB:
    listB.append(float(i))

for i in listB:
    magB+=(i**2)
magB=sqrt(magB)

#subtraction and addition
for i in range(len(listA)):
    listAdd.append(listA[i] + listB[i])
for i in range(len(listB)):
    listSub.append(listA[i] - listB[i])

#dot product
for i in range(len(listA)):
    product.append(listA[i] * listB[i])
for i in range(len(product)):
    dotprod+=product[i]

#output
print(f'The magnitude of vector A is {magA:.5f}')
print(f'The magnitude of vector B is {magB:.5f}')
print(f'A + B is {listAdd}')
print(f'A - B is {listSub}')
print(f'The dot product is {dotprod:.2f}')


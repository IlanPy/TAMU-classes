# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 6 Infividual #3
# Date:         28 September 2022
from math import *

#input
print(f'Enter a value for n: ', end='')
n = int(input())
sum = 0
j = 0 
i= n+1
count=0
r=0
sum2=0

#for loop
for i in range(1,n):
    sum+=i

r=int((-2*n-1+sqrt(8*(n**2)+1))/2)

for i in range (n+1,n+r+1):
    sum2+=i
    print(i)
if sum2==sum:
    print(f'{n} is a balancing number with r={r}')
else:
    print(f'{n} is not a balancing number')

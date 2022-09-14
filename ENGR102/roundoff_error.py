

############ Part A ############ 
a = 1 / 7
print(f'a = {a}')
b = a * 7
# value is 1.0
print(f'b = a * 7 = {b}')
c = 2 * a
d = 5 * a
f = c + d
# value is 0.9999999999999999
print(f'f = 2 * a + 5 * a = {f}')
from math import sqrt
from re import M
x = sqrt(1 / 3)
print(f'x = {x}')
y = x * x * 3
#value is 1.0
print(f'y = x * x * 3 = {y}')
z = x * 3 * x
#value is 0.9999999999999999
print(f'z = x * 3 * x = {z}')

############ Part B ############ 
TOL = 1e-10
# check if b and f are equal within specified tolerance
if abs(b-f) < TOL:
    print(f'b and f are equal within tolerance of {TOL}')
else:
    print(f'b and f are NOT equal within tolerance {TOL}')
if abs(y-z) < TOL:
    print(f'y and z are equal within tolerance of {TOL}')
else:
    print(f'y and z are NOT equal within tolerance {TOL}')

############ Part C ############ 
m = 0.1
print(f'm = {m}')
n = 3 * m
print(f'n = 3 * m = 0.3 {n==0.3}')
p = 7 * m
print(f'p = 7 * m = 0.7 {p==0.7}')
q = n + p
print(f'q = n + p = 1 {q==1}')
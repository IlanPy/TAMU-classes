'''
#22
vector1 = (1, 2, 3) 
vector2 = (2, 3, 4) 
dotp = vector1 * vector2 
print(f"The dot product is {dotp}")

#23
mystr = "Howdy" 
mylist = [2, 0, 2, 0] 
mytuple = (mystr, mylist) 
mylist[3] = 6 
print(mytuple) 

#24
def plus1_3(x): 
    return (x + 1, x + 3) 
print(plus1_3(2)[0]) 

#25
def myfun(): 
    '''This function prints a message.''' 
    print("Gig 'em Aggies!") 
help(myfun) 

#26
def myfunction(a, b=5, c): 
    return a * b * c 
print(myfunction(1, 2, 3)) 

#27 
def add1(x): 
    if x + 1 < 10: 
        return x + 1 
    else: 
        return 'Too big!' 
print(add1(1), add1(24)) 

#28
x = 4 
y = timestwo(x) 
def timestwo(x): 
    return x * 2 
print(y) 

#29
mydict = {'Ann' : 18, 'Bob' : 20, 'Charlie' : 19} 
if 'Joe' in mydict: 
    print("Joe is here") 
elif 'Ann' in mydict: 
    print("Hi Ann") 
else: 
    print("Anyone?") 
 
#30
mydict = {} 
mylist = [1, 2, 3, 4, 5] 
mydict['Length'] = len(mylist) 
mydict['Max'] = max(mylist) 
mydict['Min'] = min(mylist) 
mydict['Crazy'] = mylist[1] * mylist[3] - mylist[-1] 
for i in mydict: 
    print(f"{i}: {mydict[i]}") 
 
#31
mystr = "Howdy! Welcome to Texas A&M Engineering!" 
mylist = mystr.split() 
newstr = ''  # empty string 
for i in range(3, len(mylist)): 
    newstr += mylist[i] + ' ' 
print(mylist[0][:5] + ' ' + newstr[:-2] + ' students!') 
 
#32
mylist = [5, 3, 7, 9, 1, 2] 
mylist.pop() 
mylist.insert(2, 4) 
mylist.sort() 
for i in mylist: 
    print(i, end = ' ') 
 
#33
number = input("Enter a number: ")  # assume the user enters 5.0 
try: 
    x = int(number) 
    print(f"x is the integer {x}") 
except: 
    x = float(number) 
    print(f"x is the float {x}") 

#34
import numpy as np 
mygrid = np.arange(9).reshape(3, 3) 
print(mygrid[0]) 
print(mygrid[2][2]) 
 
#35
import numpy as np 
x = np.linspace(1.0, 10.0, 10) 
y = x ** 2 - 1 
with open('zfile.txt', 'w') as zfile: 
    zfile.write('x\ty\n') 
    for i in range(len(x)): 
        mystr = str(x[i]) + '\t' + str(y[i]) 
        zfile.write(mystr + '\n') 
with open('zfile.txt') as myfile: 
    all_of_it = myfile.read().split('\t') 
output = ','.join(all_of_it) 
print(output) 
 
#36
import numpy as np 
import matplotlib.pyplot as plt 
x = np.linspace(-2, 2, 25) 
y1 = x 
y2 = x ** 2 
plt.plot(x, y1, 'g', linewidth = 3) 
plt.plot(x, y2, 'k', marker = 'o', markerfacecolor = 'b') 
plt.axis([-2, 2, -2, 4]) 
plt.xlabel('x') 
plt.ylabel('f(x)') 
plt.title('Plots for 2 polynomials') 
plt.legend(['straight', 'curved'], loc = 'upper center') 
plt.show() 

# 31 is HARD
# 32 pop() pops the last element
#ans
22. Error, cannot multiply tuples
23. ('Howdy', [2,0,2,6])
24. 3
25. Help on function myfun in module __main__:
    my fun()
        This function prints a message.
26. Error, non default argument follows default argument
27. 2 Too Big!
28. Error, calls function before defined
29. Hi Ann
30. Length: 5
    Max: 5
    Min: 1
    Crazy: 3
31. Howdy Texas A&M Engineering students!
32. 1 3 4 5 7 9
33. Enter a number: 5.0
    x is the float 5.0
34. [0 1 2]
    8
35. x,y
    1.0,0.0
    2.0,3.0
    4.0,15.0
    5.0,24.0
    6.0,35.0
    7.0,48.0
    8.0,63.0
    9.0,90.0
    10.0,99.0

'''

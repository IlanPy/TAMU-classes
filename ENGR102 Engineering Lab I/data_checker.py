'''Write a Python program that reads the contents of this file, assigns the header lines to a variable 
that is a list of strings, and assigns the data to a variable that is a floating point NumPy array that 
contains all of the data in the file. (The data should be in an 𝑛 x 3 array.) Then, find and print the 
minimum temperature and maximum windspeed recorded in the file. Write this code using standard 
file I/O commands; do not use any csv reader that you may know of in some Python package.'''
import numpy as np
file = open('data.dat','r')

file.readline()
headers = file.readline().strip().split(',')
file.readline()
arr = []
for line in file:
	arr.append(line.strip().split(','))
	for i in range(len(arr[-1])):
		arr[-1][i] = float(arr[-1][i])
np_arr = np.array(arr)
min = np_arr[0][1]
max = np_arr[0][2]
for i in range(len(np_arr)):
	if min > np_arr[i][1]:
		min = np_arr[i][1]
	if max < np_arr[i][2]:
		max = np_arr[i][2]
file.close()
        
print(headers)
        
print(f'Minimum temperature is {min} F\nMaximum windspeed is {max} knots')
#import
import numpy as np

#message and read key
message = 'I1O5B5N3O5I1I1N2N3O5B5N3O1I5G5O5'
myfile = open('mod12activity.txt', 'r')
keylist = myfile.readlines()
letter = []

#put key in 5x5 matrix
for i in range(len(keylist)):
    keylist[i] = keylist[i].strip()
keymatrix = np.array(keylist).reshape(5,5)

#set top row and side
toprow = 'BINGO'
side = '12345'

#num so dont have to convert to int
num = '0123456789'

#check index and trace back to key
s=0
for i in message:
    if i in num:
        index1 = side.index(i)
    else:
        index2 = toprow.index(i)
    s+=1
    if s%2==0 and s!=0:
        letter.append(keymatrix[index1, index2])

#print each letter in key
for i in range(len(letter)):
    print(letter[i], end = '')
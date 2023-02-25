import matplotlib.pyplot as plt
import statistics as stat
from math import sqrt

import matplotlib.pyplot as plt
import statistics as stat
from math import sqrt

import math
myfile = open("Example_4.csv", "r")
myfile.readline()
orangex = []
orangey = []
greenx=[]
greeny= []
pinkx=[]
pinky=[]
areas = []
length = []
width =[]
data = []

for i in myfile:
    i = i.split(',')
    if i[3] != '' and i[4] !='' and i[12]!='' and i[13]!='' and i[21]!='' and i[22]!='':
        greenx.append(float(i[3]))
        greeny.append(float(i[4]))
        pinkx.append(float(i[12]))
        pinky.append(float(i[13]))
        orangex.append(float(i[21]))
        orangey.append(float(i[22]))
        
for i in range(len(orangex)):
    length.append(math.sqrt((greenx[i]-orangex[i])**2+(greeny[i]-orangey[i])**2))
    width.append(math.sqrt((greenx[i]-pinkx[i])**2+(greeny[i]-pinky[i])**2))
    data.append(length[i]*width[i])
    
#part 2 and 4
average_length = sum(length)/len(length)
average_width = sum(width)/len(width)
area1 = average_length*average_width

# plot the histogram
# bins = 8 specifies 8 bins
# facecolor is the color of the bars
# the ec (edgecolor) keyword makes the edges of the bars black  
plt.hist(data, bins = 15, facecolor = 'gray', ec = 'black')
# don't forget the labels!
plt.xlabel('Concrete Compressive Strength (MPa)')
plt.ylabel('Number of measurements')
plt.title('Measurements of Concrete Compressive Strength')
plt.show()


print('Mean:', stat.mean(data), 'in')
print('Median:', stat.median(data), 'in')
# if more than 1 mode exists, stat.mode(data) returns an error
try:
    mymode = stat.mode(data)
    print('Mode:', mymode, 'in')
except:
    # hacky way of identifying all the modes (if any)
    counts = [data.count(x) for x in set(data) if data.count(x) > 1]
    if counts == []:
        print('Mode: none')
    else:
        maxcount = max(counts)
        modes = [x for x in set(data) if data.count(x) == maxcount]
        modes.sort()
        print('Modes:', modes, 'in')
print('Min:', min(data), 'in')
print('Max:', max(data), 'in')
print('Variance:', stat.variance(data), 'in^2')
print('Pop variance:', stat.pvariance(data), 'in^2')
print('St dev:', stat.stdev(data), 'in')
print('Pop st dev:', stat.pstdev(data), 'in')
print('Standard error:', stat.pstdev(data) / sqrt(len(data)), 'in')

import statistics as st
import numpy as np
import math
from matplotlib import pyplot as plt
myfile = open("lab_2_measuring_stick - lab_2_measuring_stick.csv", "r")
x1_list = []
x2_list = []
y1_list = []
y2_list = []
distance = []
for i in myfile:
    lst = i.split(',')
    x1_list.append(int(lst[3].strip(',')))
    y1_list.append(int(lst[4].strip(',')))
    x2_list.append(int(lst[21].strip(',')))
    y2_list.append(int(lst[22].strip(',')))

for i in range(len(x1_list)):
    distance.append(math.sqrt((x2_list[i]-x1_list[i])**2+(y2_list[i]-y1_list[i])**2))
average = sum(distance)/len(distance)
print(average)

unc_distance = st.stdev(distance)/math.sqrt(len(distance))

print(unc_distance)

print('---------------------------')
print('divie 300, divide unc by 3')
print(f'{average/300} +- {unc_distance/3}')

mypluck = open("lab2_a.csv", "r")
x_pos = []
y_pos = []
x_pos_av = []
y_pos_av = []
x_vel = []
y_vel = []
x_vel_av = []
y_vel_av = []
x_acc = []
y_acc = []
x_acc_av = []
y_acc_av = []
time = []
mag_acc = []
grav = []
mypluck.readline()
for i in mypluck:
    lst = i.split(',')
    time.append(float(lst[0].strip(','))/1000)
    x_pos.append(float(lst[2].strip(','))/((average/300)*1000))
    y_pos.append(float(lst[3].strip(','))/((average/300)*1000))

for i in range(len(time)-2):
    x_pos_av.append((x_pos[i]+x_pos[i+1]+x_pos[i+2])/3.0)
    y_pos_av.append((y_pos[i]+y_pos[i+1]+y_pos[i+2])/3.0)
    
for i in range(len(time)-4):
    x_vel.append((x_pos_av[i+2]-x_pos_av[i])/(time[i+2]-time[i]))
    y_vel.append((y_pos_av[i+2]-y_pos_av[i])/(time[i+2]-time[i]))
    
for i in range(len(time)-6):
    x_vel_av.append((x_vel[i]+x_vel[i+1]+x_vel[i+2])/3.0)
    y_vel_av.append((y_vel[i]+y_vel[i+1]+y_vel[i+2])/3.0)

for i in range(len(time)-8):
    x_acc.append((x_vel_av[i+2]-x_vel_av[i])/(time[i+2]-time[i]))
    y_acc.append((y_vel_av[i+2]-y_vel_av[i])/(time[i+2]-time[i]))
    
for i in range(len(time)-10):
    x_acc_av.append((x_acc[i]+x_acc[i+1]+x_acc[i+2])/3.0)
    y_acc_av.append((y_acc[i]+y_acc[i+1]+y_acc[i+2])/3.0)
    
for i in range(len(x_acc_av)):
    mag_acc.append(math.sqrt(x_acc_av[i]**2+y_acc_av[i]**2))

for i in range(len(y_acc_av)):
    grav.append(mag_acc[i]/math.sin(3.6*(math.pi/180)))

print(st.mean(grav))
mypluck.close()
myfile.close()

time2=[]
for i in range(len(time)-8):
    time2.append(time[i])

fig,ax = plt.subplots()
ax.plot(time2,y_acc)
plt.show

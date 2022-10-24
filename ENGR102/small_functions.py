# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 9a
# Date:         24 October 2022
from math import *
from statistics import median

#volume of a bead
def parta(radsphere, r):
    volume = (4/3)*pi*(radsphere**3)
    theta = asin(r/radsphere)
    volcap = (pi/3)*(radsphere**3)*(2+cos(theta))*((1-cos(theta))**2)
    a = 2*pi*radsphere**2*(1-cos(theta))
    h = 2*radsphere - 2*(a/(2*pi*radsphere))
    volume1 = pi*r**2*h
    finalvolume = volume-volume1-2*volcap
    return(finalvolume)

#function to see if consecutive odd numbers add
def partb(n):
    list1=[]
    sum=0
    for i in range(1,n,2):
        list1.append(i)
    for i in range(1,n,2):
        list0 = list1[i:]
        list2=[]
        sum=0
        for j in list0:
            sum +=j
            list2.append(j)
            if sum==n:
                return list2
            elif sum>n:
                break
    return False

#function to print business card
def partc(border, name, company, email):
    list1 = [len(border), len(name), len(company), len(email)]
    length = max(list1)
    string0 = border*(length+6)
    string1 = name.center(length)
    string2 = border + '  ' + string1 + '  ' + border
    string3 = company.center(length)
    string4 = border + '  ' + string3 + '  ' + border
    string5 = email.center(length)
    string6 = border + '  ' + string5 + '  ' + border
    finalstring = string0 + '\n' + string2 + '\n' + string4 + '\n'+string6 + '\n' + string0
    return finalstring

#function for max, min, median
def partd(list1):
    minimum = min(list1)
    maximum = max(list1)
    med = median(list1)
    return minimum, med, maximum

#function to calculate velocity
def parte(t, d):
    vel = []
    for i in range(len(t)-1):
        speed = (d[i+1]-d[i])/(t[i+1]-t[i])
        vel.append(speed)
    return vel

#function to calculate if two numbers add to 2026
def partf(nums):
    for i in range(len(nums)):
        for j in range(len(nums)-1):
            if(nums[i]+nums[j])==2026:
                return nums[i]*nums[j]
    return False

print(partb(75))
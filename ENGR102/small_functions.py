# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 9a
# Date:         24 October 2022
from math import *
def parta(radsphere, r):
    volume = (4/3)*pi*(radsphere**3)
    theta = asin(r/radsphere)
    volcap = (pi/3)*(radsphere**3)*(2+cos(theta))*((1-cos(theta))**2)
    a = 2*pi*radsphere**2*(1-cos(theta))
    h = 2*radsphere - 2*(a/(2*pi*radsphere))
    volume1 = pi*r**2*h
    finalvolume = volume-volume1-2*volcap
    return(finalvolume)


def partb(n):
    list1=[]
    for i in range(1,n):
        if i%2!=0 and (i+2)+(i)==n:
            list1.append(i)
            list1.append(i+2)
            return list1
    return False

def partc(border, name, company, email):
    list1 = [len(border), len(name), len(company), len(email)]
    length = max(list1)
    string0 = '*'*(length+6)
    string1 = name.center(length)
    string2 = '*  ' + string1 + '  *'
    string3 = company.center(length)
    string4 = '*  ' + string3 + '  *'
    string5 = email.center(length)
    string6 = '*  ' + string5 + '  *'
    finalstring = string0 + '\n' + string2 + '\n' + string4 + '\n'+string6 + '\n' + string0
    return finalstring

def partd(list0):
    list1=[]
    for i in len(list0):
        list1.append(list0[i])
    minimum = min(list1)
    maximum = max(list1)
    median = 0
    n = len(list1)
    if n==1:
        median = list1[0]
    else:
        for i in range(n-1):
            for j in range(n-1-i):
                if list1[j] > list1[j+1]:
                    list1[j], list1[j+1] = list1[j], list1[j+1]
        middle = n/2
        median = list1[middle]
    return minimum, median, maximum

def parte(time, distance):
    vel = []
    for i in len(time):
        speed = distance/time
        vel.append(speed)
[1,3,4,3,2,5]
def partf(nums):
    for i in len(nums):
        for j in len(nums-1):
            if(nums[i]+nums[j])==2026:
                return nums[i]*nums[j]
    return False

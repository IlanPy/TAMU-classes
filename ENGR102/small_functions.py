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
    string0 = border*(length+6)
    string1 = name.center(length)
    string2 = border + '  ' + string1 + '  ' + border
    string3 = company.center(length)
    string4 = border + '  ' + string3 + '  ' + border
    string5 = email.center(length)
    string6 = border + '  ' + string5 + '  ' + border
    finalstring = string0 + '\n' + string2 + '\n' + string4 + '\n'+string6 + '\n' + string0
    return finalstring

def partd(list1):
    list1=[]
    minimum = min(list1)
    maximum = max(list1)
    med = median(list1)
    return minimum, med, maximum

def parte(t, d):
    vel = []
    for i in range(len(t)-1):
        speed = (d[i+1]-d[i])/(t[i+1]-t[i])
        vel.append(speed)
    return vel

def partf(nums):
    for i in range(len(nums)):
        for j in range(len(nums)-1):
            if(nums[i]+nums[j])==2026:
                return nums[i]*nums[j]
    return False
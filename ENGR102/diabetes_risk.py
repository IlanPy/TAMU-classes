#  By submitting this assignment, I agree to the following:
#  "Aggies do not lie, cheat, or steal, or tolerate those who do."
#  "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#              	Dave Wright
# Section:      	501
# Assignment:   	Diabetes Risk Planning
# Date:         	19 September 2022

from math import *

#################### PART A #######################
#Question 1
print(f'Enter your sex (M/F): ', end = '')
sex = input()
'''
if(sex != 'm' and sex != 'M' and sex != 'f' and sex != 'F'):
    print("You entered an invalid sex")
    exit()
'''

#Question 2
print(f'Enter your age (years): ', end = '')
age = int(input())

#Question 3
print(f'Enter your BMI: ', end = '')
bmi = float(input())

#Question 4
print(f'Are you on medication for hypertension (Y/N)? ', end = '')
hypertension = input()

#Question 5
print(f'Are you on steroids (Y/N)? ', end = '')
steroids = input()

#Question 6
smoker = 0
print(f'Do you smoke cigarettes (Y/N)? ', end = '')
cigarettes = input()

#Question 7
print(f'Did you used to smoke (Y/N)? ', end = '')
smoke = input()

#Question 8
sibling = ''
parent = ''
family = 0
print(f'Do you have a family history of diabetes (Y/N)? ', end = '')
familyHist = input()
if(familyHist == 'y' or familyHist == 'Y'):
    print('Both parent and sibling (Y/N)? ', end='')
    sibling = input()

#################### PART B #######################

#assigning value for sex
if(sex == 'f' or sex == 'F'):
    sex = 0.879
else:
    sex = 0

#assigning value for bmi
if(bmi < 25):
    bmi = 0
elif(25 <= bmi <= 27.49):
    bmi = 0.699
elif(27.5 <= bmi <= 29.99):
    bmi = 1.97
elif(30 <= bmi):
    bmi = 2.518

#assigning value for hypertension
if(hypertension == 'Y' or hypertension == 'y'):
    hypertension = 1.222
elif(hypertension == 'n' or hypertension == 'N'):
    hypertension = 0

#assigning value for steroids
if(steroids == 'Y' or steroids == 'y'):
    steroids = 2.191
elif(steroids == 'n' or steroids == 'N'):
    steroids = 0

#assigning value for smoker
if(cigarettes == 'Y' or cigarettes == 'y'):
    smoker = 0.855
elif((smoke == 'Y' or smoke == 'y') and (cigarettes == 'n' or cigarettes == 'N')):
    smoker = -0.218
elif((cigarettes == 'n' or cigarettes == 'N') and (smoke == 'n' or smoke == 'N')):
    smoker = 0

#assigning value for family history
if(familyHist == 'n' or familyHist == 'N'):
    family = 0
elif(sibling == 'n' or sibling == 'N'):
    family = 0.728
elif(sibling == 'Y' or sibling == 'y'):
    family = 0.753

#################### PART C #######################

#Calculating risk
n = 6.322 + sex - (0.063*age) - bmi - hypertension - steroids - smoker - family
risk = 100/(1+e**n)

print(f'Your risk of developing type-2 diabetes is {risk:.1f}%')
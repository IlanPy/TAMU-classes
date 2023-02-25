import statistics as st
import numpy as np
myfile = open("Concrete_Data_convert.csv", "r")
myfile.readline()
water = [] #for part A
fine_aggregate = [] #for part B
cement = [] #for part C
concrete_compressive = [] #for part D
#Seperate columns into lists
for i in myfile:
    i = i.split(',')
    water.append(float(i[3]))
    fine_aggregate.append(float(i[6]))
    cement.append(float(i[0]))
    concrete_compressive.append(float(i[8]))

######## Part A ########
def part_A(water):
    #Calculate the mean, median, and mode
    meanA = st.mean(water)
    medianA = st.median(water)
    modeA = st.mode(water)
    print(f'Mean = {meanA} kg/m^3\nMedian = {medianA} kg/m^3\nMode = {modeA} kg/m^3')

######## Part B ########
def part_B(fine_aggregate):
    #Calculate the range, variance, and standard deviation
    maxB = max(fine_aggregate)
    minB = min(fine_aggregate)
    rangeB = maxB-minB
    varianceB = np.var(fine_aggregate)
    standard_devB = np.std(fine_aggregate)
    print(f'Range = {rangeB} kg/m^3\nVariance = {varianceB} (kg/m^3)^2'
          + f'\nStandard Deviation = {standard_devB} kg/m^3')
    
######## Part C ########
def part_C(cement):
    #Calculate mean and standard error
    meanC = st.mean(cement)
    cement = np.array(cement)
    standard_errorC = np.std(cement)/np.sqrt(np.size(cement))
    print(f'Mean = {meanC} kg/m^3\nStandard Error = {standard_errorC} kg/m^3')

######## Part C ########
def part_D(concrete_compressive):
    #Calculate mean and standard error
    meanD = st.mean(concrete_compressive)
    concrete_compressive = np.array(concrete_compressive)
    standard_errorD = np.std(concrete_compressive)/np.sqrt(np.size(concrete_compressive))
    print(f'Mean = {meanD} kg/m^3\nStandard Error = {standard_errorD} kg/m^3')

print('---------- PART A ----------')
part_A(water)
print('---------- PART B ----------')
part_B(fine_aggregate) #kg, kg^2, kg
print('---------- PART C ----------')
part_C(cement) #kg, kg
print('---------- PART D ----------')
part_D(concrete_compressive) #MPa, MPa

myfile.close()
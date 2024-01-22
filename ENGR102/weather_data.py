# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 11 indv #3
# Date:         9 November 2022

myfile = open("WeatherDataCLL.csv", "r")
content = myfile.readlines()
content.pop(0)

months = ['January', 'February', 'March', 'April', 
    'May', 'June', 'July', 'August', 'September', 'October', 
    'November', 'December']

#the maximum temperature seen over the 3-year period 
def max_temp():
    split1 = content[0].split(',')
    max = int(split1[4])
    for i in content:
        split = i.split(',')
        if(int(split[4])>max):
            max = int(split[4])
    return max

#the minimum temperature seen over the 3-year period
def min_temp():
    split1 = content[0].split(',')
    min = int(split1[5])
    for i in content:
        split = i.split(',')
        if (int(split[5])<min):
            min = int(split[5])
    return min

#the average daily precipitation over the 3-year period
def avg_prec():
    sum = 0.0
    for i in content:
        split = i.split(',')
        sum += float(split[2])
    length = len(content)
    average = sum/length
    return average

#Calculate the mean of the maximum temperatures
def mean_maxtemp(month, year):
    imonth = 0
    sum = 0.0
    days = 0
    for i in range(len(months)):
        if months[i] == month:
            imonth = i+1
    
    for i in range(len(content)):
        split = content[i].split(',')
        secondsplit = split[0].split('/')
        if(int(secondsplit[0]) == imonth and int(secondsplit[2]) == year):
            sum += float(split[4])
            days += 1
    average = sum/days
    return average

#Calculate the mean daily wind speed
def mean_windspeed(month, year):
    imonth = 0
    sum = 0.0
    days = 0
    for i in range(len(months)):
        if months[i] == month:
            imonth = i+1
    
    for i in range(len(content)):
        split = content[i].split(',')
        secondsplit = split[0].split('/')
        if(int(secondsplit[0]) == imonth and int(secondsplit[2]) == year):
            sum += float(split[1])
            days += 1
    average = sum/days
    return average

#Calculate the percentage of days with non-zero precipitation
def nonzero_percent(month, year):
    imonth = 0
    counter = 0
    days = 0
    for i in range(len(months)):
        if months[i] == month:
            imonth = i+1

    for i in range(len(content)):
        split = content[i].split(',')
        secondsplit = split[0].split('/')
        if(int(secondsplit[0]) == imonth and int(secondsplit[2]) == year):
            if float(split[2]) != 0.0:
                counter +=1
            days += 1
    percent = (counter/days)*100
    return percent

#call functions
max = max_temp()
min = min_temp()
average = avg_prec()

#output
print(f'3-year maximum temperature: {max} F')
print(f'3-year minimum temperature: {min} F')
print(f'3-year average precipitation: {average:.3f} inches')

#input
print()
month = input('Please enter a month: ')
year = input('Please enter a year: ')
year = int(year)

#call functions
maxtemp = mean_maxtemp(month, year)
windspeed = mean_windspeed(month, year)
nonzero = nonzero_percent(month, year)

#output
print()
print(f'For {month} {year}:')
print(f'Mean maximum daily temperature: {maxtemp:.1f} F')
print(f'Mean daily wind speed: {windspeed:.2f} mph')
print(f'Percentage of days with precipitation: {nonzero:.1f}%')

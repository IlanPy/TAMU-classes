# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Topic 4 Activity #4
# Date:         14 September 2022

gadget = 0
print('Please enter a positive value for day: ', end = "")
days = int(input())

#if statements
if(days<0):
    print(f'You entered an invalid number!')
else:
    if(days<11):
        #works
        gadget = 5*days
    elif(days<61):
        #works
        gadget = 5*10
        gadget = gadget + 50*(days- 10)
    elif(days<101):
        gadget = 10*5 + 50*50 + ((days-60)*50 - ((days-60)*(days-60+1))/2)
    elif(days>100):
        gadget = 10*5 + 50*50 + ((101-60)*50 - ((101-60)*(101-60+1))/2)

    print(f'The total number of gadgets produced on day {days} is {int(gadget)}')
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
if(days<0):
    print(f'You entered an invalid number!')
else:
    if(days<11):
        gadget = 5*days
    elif(days<61):
        gadget = gadget + 50*days
    elif(days<102):
        base = 101-60
        height = 50 
        area = (base*height)*0.5
        base2 = 101-days
        height2 = 50 - (days - 60)
        area2 = (base2*height2)*0.5
        gadget = gadget + (area-area2)
    print(f'The total number of gadgets produced on day {days} is {gadget}')

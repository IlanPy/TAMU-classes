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
        gadget = 5*days
    elif(days<61):
        gadget = 5*10
        gadget = gadget + 50*(days- 10)
    elif(days<102):
        #something is wrong with this!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        #it is to calculate area of small square and parallelogram
        #this should equate to 3730
        gadget = (5*10) + ((91+60)*50)/2
        '''
        this is another way to solve. dont bother looking
        gadget = 5*10
        gadget += 50*(60-10)
        print(gadget)
        gadget += ((101-61)*49)*0.5
        print(gadget)
        base = 101-61
        height = 49
        area = (base*height)*0.5
        '''
        #caluclate area of small triangle of days not passed
        base2 = 101-days
        height2 = 49 - (days-61)
        area2 = (base2*height2)*0.5
        print(area2)
        #parallelogram+smallsquare-triangle
        gadget = gadget - area2
        print(gadget)

    print(f'The total number of gadgets produced on day {days} is {gadget}')
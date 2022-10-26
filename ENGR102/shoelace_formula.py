# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 6: Activity #1
# Date:         26 October 2022

#convert string to list
def getpoints(mystring):
    #split into first list
    mylist = mystring.split(' ')
    
    #split into second list
    for i in range(len(mylist)):
        mylist[i]=mylist[i].split(',')

    #convert each value to int
    for i in range(len(mylist)):
        for j in range(len(mylist[i])):
            mylist[i][j] = int(mylist[i][j])

    return mylist

#do determinant of each point
def cross(list1, list2): 
    value1 = list1[0]
    value2 = list2[1]
    value3 = list1[1]
    value4 = list2[0]
    #calculation
    cross = value1*value2 - value3*value4
    return cross

#use shoelace formula
def shoelace(list1):
    area = 0
    list2 = list1[:]
    for i in range(len(list2)-1):
        area += cross(list2[i],list2[i+1])
    maxindex = len(list2)-1
    area += cross(list2[maxindex],list2[0])
    area = area/2
    return area

def main():
    #call on functions and get input
    print('Please enter the vertices: ', end ='')
    x = input()
    list0 = getpoints(x)
    area = shoelace(list0)
    print(f'The area of the polygon is {area}')

if __name__ == '__main__': 
    main() 
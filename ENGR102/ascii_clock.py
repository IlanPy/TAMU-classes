# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB Topic 8 Team: ASCII Clock
# Date:         12 October 2022

#Get user input for clock time; store in variable "user_input" 
print('Enter the time: ')
user_input = input()
#Convert input to list; store in variable "input_as_list"
input_as_list = list(user_input)

#ASCII Template Definitions
#Define master_list as empty list; will contain the 5 lists defined below
master_list = []
#List line1 containing the first line of the ASCII form for each number/colon; append the list to master_list
line1 = ["000"," 1 ","222","333","4 4","555","666","777","888","999"," "]
master_list.append(line1)
#List line2 containing the second line of the ASCII form for each number/colon; append the list to master_list
line2 = ["0 0","11 ","  2","  3","4 4","5  ","6  ","  7","8 8","9 9",":"]
master_list.append(line2)
#List line3 containing the third line of the ASCII form for each number/colon; append the list to master_list
line3 = ["0 0"," 1 ","222","333","444","555","666","  7","888","999"," "]
master_list.append(line3)
#List line4 containing the fourth line of the ASCII form for each number/colon; append the list to master_list
line4 = ["0 0"," 1 ","2  ","  3","  4","  5","6 6","  7","8 8","  9",":"]
master_list.append(line4)
#List line5 containing the fifth line of the ASCII form for each number/colon; append the list to master_list
line5 = ["000","111","222","333","  4","555","666","  7","888","999"," "]
master_list.append(line5)


#For loop that runs 5 times to print out each number/colon
#Outer loop header
for i in range(5):
#Inner loop header - runs for every element in input_as_list
    for access_number in input_as_list:
#Access input_as_list at index corresponding to loop control variable and convert that element to int; store in "access_number"
#If the accessed element is a colon, assign 10 to variable "access_number"
        if(access_number == ':'):
            access_number = 10
        else:
            access_number = int(access_number)
#Access master_list at index corresponding to outer loop control variable
#At list accessed in master_list, access element at access_number and print it followed by space
        print(f'{master_list[i][access_number]} ', end = "")
    print('\n', end ="")

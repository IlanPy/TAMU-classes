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

# (Jordan) Get user input for clock time; store in variable "user_input" 

# (Jordan) Convert input to list; store in variable "input_as_list"


# ASCII Template Definitions
# (Jordan) Define master_list as empty list; will contain the 5 lists defined below

# (Robert) List line1 containing the first line of the ASCII form for each number/colon; append the list to master_list

# (Robert) List line2 containing the second line of the ASCII form for each number/colon; append the list to master_list

# (Robert) List line3 containing the third line of the ASCII form for each number/colon; append the list to master_list

# (Dave) List line4 containing the fourth line of the ASCII form for each number/colon; append the list to master_list

# (Dave) List line5 containing the fifth line of the ASCII form for each number/colon; append the list to master_list



# For loop that runs 5 times to print out each number/colon
# (Ilan) Outer loop header
for i in range(5):
    # (Ilan) Inner loop header - runs for every element in input_as_list
    for access_number in input_as_list:
        # (Ilan) Access input_as_list at index corresponding to loop control variable and convert that element to int; store in "access_number"
        # If the accessed element is a colon, assign 10 to variable "access_number"
        if(access_number == ':'):
            access_number = 10
        else:
            access_number = int(access_number)
        # (Ilan) Access master_list at index corresponding to outer loop control variable
        # At list accessed in master_list, access element at access_number and print it followed by space
        print(f'{master_list[i][access_number]} ', end = "")
    print('\n', end ="")


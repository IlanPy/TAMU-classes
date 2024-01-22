# By submitting this assignment, I agree to the following:
#  "Aggies do not lie, cheat, or steal, or tolerate those who do."
#  "I have not given or received any unauthorized aid on this assignment."

# Names:        Ilan Sela
#              	NAME OF TEAM MEMBER 2
#              	Jordan Rivas
#              	Robert Stacks
# Section:      	501
# Assignment: 	    Go Moves 
# Date:         	3 October 2022


#empty board
list0 = [['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.','.']]


#first printing of board with all periods.
#the "*" before unpackages the list
print(*list0[0], '\n', *list0[1], '\n', *list0[2], '\n', *list0[3], '\n', *list0[4],
    '\n', *list0[5], '\n', *list0[6], '\n', *list0[7], '\n', *list0[8], sep='')

#for loop that runs until the board is full
for i in range(41):
    #Question for row
    print(f'Black, what is the row you\'d like to place your stone? ', end = '')
    input1 = input()
    
    #Check if desire to stop
    if(input1.lower() == 'stop'):
        break
    
    #Question for column
    print(f'Black, what is the column you\'d like to place your stone? ', end='')
    input2 = input()

    #If desire to stop, break out of every loop
    if(input2.lower() == 'stop'):
        break

    #since list index starts at 0, subtract 1 from input to match index
    blackr = int(input1)-1
    blackc = int(input2)-1

    #check if location is empty
    check = list0[blackr][blackc]
    if(check == '.'):
        list0[blackr][blackc] = chr(9675)
    else:
        while(list0[blackr][blackc] != '.'):
            print(f'There is already a stone placed at that location. Please retry.')
            print(f'Black, what is the row you\'d like to place your stone? ', end = '')

            #check if desire to stop after reinput
            input1 = input()
            if(input1.lower() == 'stop'):
                break
            print(f'Black, what is the column you\'d like to place your stone? ', end='')
            #check if desire to stop after reinput
            input2 = input()
            if(input2.lower() == 'stop'):
                break

            #variable assignment
            blackr = int(input1)-1
            blackc = int(input2)-1
        
        #if desire to stop, exit every loop
        if(input1.lower() == 'stop' or input2.lower() == 'stop'):
            break

        #assignment stone onto board
        list0[blackr][blackc] = chr(9675)

    #output of board
    print(*list0[0], '\n', *list0[1], '\n', *list0[2], '\n', *list0[3], '\n', *list0[4],
        '\n', *list0[5], '\n', *list0[6], '\n', *list0[7], '\n', *list0[8], sep='')

    #since board gets full on black input, this will break once full
    if(i==40):
        break
    
    #Question for row
    print(f'White, what is the row you\'d like to place your stone? ', end = '')
    input1 = input()
    
    #Check if desire to stop
    if(input1.lower() == 'stop'):
        break

    #Question for column
    print(f'White, what is the column you\'d like to place your stone? ', end='')
    input2 = input()

    #Check if desire to stop
    if(input2.lower() == 'stop'):
        break
    
    #match index
    whiter = int(input1)-1
    whitec = int(input2)-1

    #check if desired spot is full
    check = list0[whiter][whitec]
    if(check == '.'):
        list0[whiter][whitec] = chr(9679)
    else:
        while(list0[whiter][whitec] != '.'):
            print(f'There is already a stone placed at that location. Please retry.')
            print(f'White, what is the row you\'d like to place your stone? ', end = '')
            input1 = input()
            #check if desire to stop in reinput
            if(input1.lower() == 'stop'):
                break
            print(f'White, what is the column you\'d like to place your stone? ', end='')
            input2 = input()
            #check if desire to stop in reinput
            if(input2.lower() == 'stop'):
                break
            
            #match index
            whiter = int(input1)-1
            whitec = int(input2)-1

        #if desired to stop, exit whole loops
        if(input1.lower() == 'stop' or input2.lower() == 'stop'):
            break

        #assignment
        list0[whiter][whitec] = chr(9679)

    #board output
    print(*list0[0], '\n', *list0[1], '\n', *list0[2], '\n', *list0[3], '\n', *list0[4],
        '\n', *list0[5], '\n', *list0[6], '\n', *list0[7], '\n', *list0[8], sep='')

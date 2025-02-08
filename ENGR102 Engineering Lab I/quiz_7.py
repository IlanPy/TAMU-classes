#initialize the counter for amount of people with a middle initial and cities with one word
book=['John A Adams        Street Name         Strong, IL          820-309823']
middleinitial=0

oneword = 0

#outer for-loop runs through the index of each string in book

for i in range(len(book)):

#strbook will be a string variable that contains the ith string

	strbook = book[i]

#nested for loop that will run through the range of the second character to the end of 

#name column (20). I do 1-19 instead of 0-20 because we will check the value before and 

#after. I.e. dont want to go out of range

	for j in range(1,19):

#if there is a space before, after, and is not a space itself, then it is is a middle initial

		if (strbook[j-1] == ' ') and (strbook[j+1] == ' ') and (strbook[j] != ' '):

			middleinitial+=1

#use a break statement because a name cannot have multiple middle initial

			break

#create a variable citystate and initialize it to the city, state column. And split it with space.

#example: if city is "Science Town, IL", desired outcome is: ["Science", "Town,", "IL"]

#if only "Science, IL", desired outcome is: ["Science,", "IL"],

	citystate = strbook[40:60].split(' ')

#if the length of list has only 2 elements, i.e. one-word city and state, then add 1 to the 

#counter (look at previous comment example)

	if len(citystate)==2:

		oneword+=1

#exit for-loop and print output

print(f'There are {middleinitial} people with a middle initial.')

print(f'There are {oneword} cities with only one word in their name.')
# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 11 indv #2
# Date:         9 November 2022

#open the files
myfile = open("game.txt", "r")
coins_file = open("coins.txt", "w")

#create a list of each line
content = myfile.readlines()
coin_counter = 0
i=0

#enter while-loop to read each element
while i < len(content):
    splitcontent = content[i].split()
    #if coin, write value into file
    if 'coin' in content[i]:
        coin_counter += int(splitcontent[1])
        coins_file.write(str(int(splitcontent[1])))
        coins_file.write('\n')
        i+=1
    #if jump, change value of element
    elif 'jump' in content[i]:
        inter = int(splitcontent[1])
        i = i+inter
    #none, read next line
    elif 'none' in content[i]:
        i+=1

#close files
myfile.close()
coins_file.close()
print(f'Total coins collected: {coin_counter}')
        
# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 11 team #1
# Date:         9 November 2022

#input file name
file_name = input('Enter the name of the file: ')

#open files
myfile = open(file_name, "r")
writefile = open('valid_passports.txt', "w")
content = myfile.readlines()
newlist = []
valid = 0

#loop to make a list with each passport per line
s=0
for i in range(len(content)):
    if content[i] == '\n':
        newlist.append(''.join(content[s:i]))
        s=i

#loop to check if valid and write
for i in newlist:
    if('byr' in i and 'iyr' in i and 'eyr' in i and 'hgt' in i and 'ecl' in i and 'pid' in i and 'cid' in i):
        valid+=1
        writefile.write(i)
        writefile.write('\n')

#print and close    
print(f'There are {valid} valid passports')
myfile.close()
writefile.close()

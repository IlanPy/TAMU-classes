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
writefile = open('valid_passports2.txt', "w")
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
s=0
for i in newlist:
    count = 0
    if('byr' in i and 'iyr' in i and 'eyr' in i and 'hgt' in i and 'ecl' in i and 'pid' in i and 'cid' in i):
        newlst = i.split(':')
        for j in range(len(newlst)):
            if 'byr' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if len(secondnewlst[0]) == 4 and int(secondnewlst[0]) >= 1920 and int(secondnewlst[0]) <= 2005:
                    count+=1
            elif 'iyr' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if len(secondnewlst[0]) == 4 and int(secondnewlst[0]) >= 2012 and int(secondnewlst[0]) <= 2022:
                    count+=1
            elif 'eyr' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if len(secondnewlst[0]) == 4 and int(secondnewlst[0]) >= 2022 and int(secondnewlst[0]) <= 2032:
                    count+=1
            elif 'hgt' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if 'cm' in secondnewlst[0]:
                    str = secondnewlst[0]
                    stri = str[:-2]
                    if int(stri) >= 150 and int(stri) <= 193:
                        count+=1
                elif 'in' in secondnewlst[0]:
                    str = secondnewlst[0]
                    stri = str[:-2]
                    if int(stri) >= 59 and int(stri) <= 76:
                        count+=1
            elif 'ecl' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if secondnewlst[0] == 'amb' or secondnewlst[0] == 'blu' or secondnewlst[0] == 'brn' or secondnewlst[0] == 'gry' or secondnewlst[0] == 'grn' or secondnewlst[0] == 'hzl' or secondnewlst[0] == 'oth':
                    count+=1
            elif 'pid' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if len(secondnewlst[0]) == 9:
                    count+=1
            elif 'cid' in newlst[j]:
                secondnewlst = newlst[j+1].split()
                if int(secondnewlst[0]) >= 100 and int(secondnewlst[0]) <= 1000:
                    count +=1
        if count == 7:
            valid+=1
            if(s==0):
                writefile.write(i[1:])
            else:
                writefile.write(i)
            s+=1
myfile.close()
writefile.close()

print(f'There are {valid} valid passports')
# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 11 team #1
# Date:         9 November 2022

print('Enter the name of the file: ', end='')
file_name = input()
with open(file_name, "r") as infile:
    file_aslist = list(file_name)
    valid = 0
    for i in file_aslist:
        if('byr' in i and 'iyr' in i and 'eyr' in i and 'hgt' in i and 'ecl' in i and 'pid' in i and 'cid' in i):
            valid +=1
    print(f'There are {valid} valid passports')


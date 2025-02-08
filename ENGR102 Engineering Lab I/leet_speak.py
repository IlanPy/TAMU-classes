# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 7b
# Date:         5 October 2022

#input
print("Enter some text: ", end='')
words = input()
#mylist = words.split()
mydict = {'a':'4', 'e':'3','o':'0','s':'5','t':'7'}
#s=0

leetwords = ''
for i in words:
    if i in mydict:
        k = mydict[i]
        leetwords+=k
    else:
        leetwords+=i
print(f'In leet speak, "{words}" is: \n{leetwords}')



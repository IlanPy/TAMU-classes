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
mylist = words.split()
s=0

#loop words
for i in mylist:
    #loop characters in words
    for k in i:
        #assignment
        mystr = "".join(mylist[s])
        if k=='a':
            mystr = mystr.replace('a', '4')
        elif k=='e':
            mystr = mystr.replace('e', '3')
        elif k=='o':
            mystr = mystr.replace('o', '0')
        elif k=='s':
            mystr = mystr.replace('s', '5')
        elif k=='t':
            mystr = mystr.replace('t', '7')
        
        mylist[s] = mystr
    s+=1

#output
mystr = " ".join(mylist)
print(f'In leet speak, "{words}" is: \n{mystr}')

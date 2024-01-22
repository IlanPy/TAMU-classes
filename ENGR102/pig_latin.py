# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 7a
# Date:         5 October 2022

#print for input
print('Enter word(s) to convert to Pig Latin: ', end ='')
mystr = input()

#variables
consonants = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r',
            's','t','v','w','x','z']
vowels = ['a','e','i','o','u','y']
mylist = mystr.split(' ')
s=0

truce = True
copylist = mylist.copy()

#consonants checking
for i in mylist:
    truce = True
    for j in i:
        for k in consonants:
            if(j.lower() == k):
                i+=j
                i = i[1:]
                mylist[s] = i
                truce = False
                break
            else:
                truce = True
        if truce:
            break

#vowel and 'ay' checking
    copystr = "".join(copylist[s])
    mystr = "".join(mylist[s])
    if copystr != mystr:
        mylist[s] += 'ay'
    else:
        for k in vowels:
            if(mystr[0] == k):
                mylist[s] += 'yay'
    s+=1

newstr = " ".join(mylist)
inputstr = " ".join(copylist)

print(f'In Pig Latin, "{inputstr}" is: {newstr}')

newstr = " ".join(mylist)
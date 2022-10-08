# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 7c
# Date:         5 October 2022

print('Enter a four-digit integer: ', end ='')
digit = input()
mylist = []
revlist = []
mystr = ''
revstr = ''
store = [digit]

for i in digit:
    mylist.append(i)

for i in digit:
    revlist.append(i)


for i in range(8):
    #convert to int list
    if(len(mylist)<4):
        mylist.insert(0,0)
        revlist.insert(0,0)
    s=0
    for i in mylist:
        mylist[s]= int(i)
        s+=1
    s=0
    for i in revlist:
        revlist[s]=int(i)
        s+=1
    #sort int list
    mylist.sort()
    revlist.sort(reverse=True)
    #conert to string list
    s=0
    for i in mylist:
        mylist[s]=str(i)
        s+=1
    s=0
    for i in revlist:
        revlist[s]=str(i)
        s+=1
    #join list into a str
    mystr = "".join(mylist)
    revstr = "".join(revlist)
    #convert string into an int
    digit = int(mystr)
    revdigit = int(revstr)
    digit = revdigit - digit
    #convert int to string
    digit = str(digit)
    #convert string to list
    s=0
    for i in digit:
        mylist[s]=i
        s+=1
    s=0
    for i in digit:
        revlist[s]=i
        s+=1
    #store a list of digits
    store.append(digit)
    if(digit == '6174'):
        break

#print
s=1
for i in store:
    print(f'{i}', end = '')
    if(s<len(store)):
        print(f' > ', end = '')
    s+=1

print(f'\n{store[0]} reaches 6174 via Kaprekar\'s routine in {len(store)-1} iterations')

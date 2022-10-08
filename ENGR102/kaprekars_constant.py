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
mystr = ''
revstr = ''
store = [digit]

while(len(digit)<4):
    digit = '0' + digit

mylist = list(digit)

revlist = list(mylist)

#repeated case
if(len(set(mylist)) == 1):
    print(f'{digit} > 0\n{digit} reaches 0 via Kaprekar\'s routine in 1 iterations')
    exit()

for i in range(8):
    #convert to int list

    #sort int list
    mylist.sort()
    revlist.sort(reverse=True)

    #join list into a str
    mystr = "".join(mylist)
    revstr = "".join(revlist)
    #convert string into an int
    digit = int(mystr)
    revdigit = int(revstr)
    digit = revdigit - digit

    #convert int to string
    digit = str(digit)
    #store a list of digits
    store.append(digit)
    digit = '0' * (4-len(digit)) + digit
    #convert string to list
    mylist = list(digit)
    revlist = list(mylist)
    if(digit == '6174'):
        break

#print
print(" > ".join(store))
print(f'{store[0]} reaches 6174 via Kaprekar\'s routine in {len(store)-1} iterations')

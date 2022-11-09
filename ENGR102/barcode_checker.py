# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 11 indv #1
# Date:         9 November 2022

with open('barcodes.txt', 'r') as myfile:
    valid = 0
    for new_line in myfile:
        mylist = list(new_line)
        if '\n' in mylist:
            mylist.remove('\n')
        mylist.pop(12)
        for s in range(len(mylist)):
            mylist[s] = int(mylist[s])
        length = len(mylist)//2
        mylist1=[]
        mylist2=[]
        for i in range(0,11,2):
            mylist1.append(mylist[i])
            mylist2.append(mylist[i+1])
        sum1 = sum(mylist1)
        sum2 = sum(mylist2)
        multiply = sum2*3
        add = sum1+multiply
        lastdigit = add%10
        subtract = 10-lastdigit
        if(subtract == (int(new_line)%10)):
            valid += 1
    print(f'There are {valid} valid barcodes')
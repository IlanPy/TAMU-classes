print(f'Enter word(s) to convert to Pig Latin: ', end ='')
consonants = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r',
            's','t','v','w','x','z']
mystr = input()
mylist = mystr.split(' ')

#for i in range((len(mylist))):
#    if mylist[i][0] == ('b' or 'B'):
#        mylist[i] += (mylist[i][0])
#        mylist[i] += 'ay'
#        stre = str(mylist[i])
#        stre = stre[1:]
#        mylist[i] = stre
for s in range(len(mylist)):
    for i in mylist:
        for j in i:
            for k in consonants:
                if(j == k):
                    i+=j
                    i = i[1:]
                    mylist[s] = i
                    print(mylist)
    



print(mylist)

newstr = " ".join(mylist)
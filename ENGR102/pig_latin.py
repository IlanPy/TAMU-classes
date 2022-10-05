print('Enter word(s) to convert to Pig Latin: ', end ='')
mystr = input()
consonants = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r',
            's','t','v','w','x','z']
vowels = ['a','e','i','o','u','y']
mylist = mystr.split(' ')
checklist = mylist
truce = True

#for i in range((len(mylist))):
#    if mylist[i][0] == ('b' or 'B'):
#        mylist[i] += (mylist[i][0])
#        mylist[i] += 'ay'
#        stre = str(mylist[i])
#        stre = stre[1:]
#        mylist[i] = stre
for s in range(len(mylist)):
    for i in mylist:
        truce = True
        for j in i:
            for k in consonants:
                if(j == k):
                    i+=j
                    i = i[1:]
                    mylist[s] = i
                    truce = False
                    break
            if truce:
                if mylist != checklist:
                    mylist[s] += 'ay'
                    break
                else:
                    break
            
                
                
    



print(mylist)

newstr = " ".join(mylist)
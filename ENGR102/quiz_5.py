print(f'Enter a 5-digit integer: ', end ="")

num = int(input())

number = num

backnum = 0

#first digit

backnum = num//10000

num = num%10000

#second digit

backnum = backnum + (num//1000)*10

num = num%1000

#third digit

backnum = backnum + (num//100)*100

num = num%100

#fourth digit

backnum = backnum + (num//10)*1000

num = num%10

#fifth digit

backnum = backnum + (num)*10000

print(f'{number} backwards is: {backnum}')
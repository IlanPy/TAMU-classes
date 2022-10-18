print('Enter the secret word: ')
x=input()
while len(x)<6:
	print('Re-enter the secret word: ')
	x=input()
lst = x.split()
print('Guess a letter: ')
y=input()
count=0
truth = True
s=0
while truth:
	for i in lst:
		if y==i:
			print('Guess another letter: ')
			y=input()
			count+=1
			s+=1
	if s==0:
		truth = False
print(f'The secret word is: "{x}". You took {count} guesses!')
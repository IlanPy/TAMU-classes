def Armstrong_number(a,b):
	lst = []
	if a>b:
		a, b = b, a
	for i in range(a,b+1):
		num = 0
		stri = str(i)
		for j in stri:
			num += int(j)**len(stri)
		if num == i:
			lst.append(i)
	return lst
valid = True
first = input('Enter an int: ')
second = input('Enter another int: ')
while valid:
	try:
		if int(first) < 0 or int(second) < 0:
			first = input('Enter pos int: ')
			second = input('Enter an pos int: ')
		else:
			valid = False
	except:
		first = input('Bad input! Try first: ')
		second = input('Try again sec int: ')
print(Armstrong_number(int(first),int(second)))
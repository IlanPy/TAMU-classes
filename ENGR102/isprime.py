'''Assume a function isprime() is available for you to use in a module called ENGR102 which 
determines whether or not a number is a prime number. The function isprime() takes in as a 
parameter a single integer, and returns either True or False. Write a Python program that takes 
as input from the user two integers. If the user gives bad input, continue to prompt them to try 
again until they enter two integers. Then, test only the odd numbers between and including those 
two numbers, to check if they are prime using the isprime() function. Have your program print a 
list of the prime numbers found. If no prime numbers were found, have your program print a 
message stating that. Start your code with: from ENGR102 import isprime. You do not 
have to write the function isprime(), you only need to call it.'''

def isprime(num):
    # define a flag variable
    flag = True
    # prime numbers are greater than 1
    if num > 1:
        # check for factors
        for i in range(2, num):
            if (num % i) == 0:
                # if factor is found, set flag to True
                flag = False
                # break out of loop
                break
    return flag

first_num = input('Enter an integer: ')
second_num = input('Enter another integer: ')
lst = []
verify = True
while verify:
	try:
		first_num = int(first_num)
		second_num = int(second_num)
		verify = False
	except:
		first_num = input('Bad input! Try again first integer: ')
		second_num = input('Try again second integer: ')
if first_num > second_num:
	first_num, second_num = second_num, first_num
for i in range(first_num, second_num+1):
    if i % 2 == 1:
	    if isprime(i):
		    lst.append(i)
print(lst)
	
number_of_students = int(input('Enter the number of students: '))
myfile = open('grades.txt','w')
myfile.write(f'Name     Score\n')
store_score = []
for i in range(number_of_students):
	name, score = input('Enter the next name and score: ').split()
	store_score.append(float(score))
	myfile.write(f'{name:<9}{float(score)}\n')
print(f'The average grade for this quiz is {sum(store_score)/number_of_students}')
myfile.close()
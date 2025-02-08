myfile = open('item_cost.dat','r')

#skip header
myfile.readline()

item, cost = myfile.readline().strip().split(',')
max = cost
max_item = item

for line in myfile:
	item, cost = line.strip().split(',')
	if float(max)<float(cost):
		max = cost
		max_item = item
print(f'The most expensive item is {max_item} and costs ${max}')


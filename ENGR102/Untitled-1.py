import math
import statistics
myfile = open("output_csv.csv", "r")
content = myfile.readlines()
newfile = open('averageslab1.csv', 'w')
content.pop(0)
content.pop(0)

voltage_list = []
average_list = []

for i in content:
    split = i.split(',')
    if "\n" in split[1]:
        new = split[1].replace('\n','')
        voltage_list.append(float(new))
    else:
        voltage_list.append(float(split[1]))
verynewlist = []
for i in range(len(voltage_list)):
    newlist = []
    sum=0
    for j in range(i+1):
        newlist.append(voltage_list[j])
        sum+=voltage_list[j]
    average=sum/(i+1)
    average_list.append(average)
    if len(newlist)>1:
        verynewlist.append(statistics.stdev(newlist)/math.sqrt(len(newlist)))


for i in range(len(verynewlist)):
    newfile.write(str(verynewlist[i])+'\n')

newfile.close()

# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Name:         Ilan Sela
# Section:      401
# Assignment:   Lab 12b
# Date:         16 November 2022

import matplotlib.pyplot as plt

myfile = open("WeatherDataCLL.csv", "r")
content = myfile.readlines()
content.pop(0)

def line_graph():
    fig = plt.figure()
    ax = fig.add_subplot(111, label = '1')
    ax2 = fig.add_subplot(111, label = '2', frame_on = False)
    for i in range(len(content)-1):
        #split a line
        split = content[i].split(',')
        #split second line
        split2 = content[i+1].split(',')
        #max temp for first and second line
        y1 = int(split[4])
        y2 = int(split2[4])
        #time
        x1 = i
        x2 = i+1
        #max temp line
        line1, = ax.plot([x1,x2],[y1,y2], color = '#FF0000')
        #wind speeds line
        y1 = float(split[1])
        y2 = float(split2[1])
        line2, = ax2.plot([x1,x2],[y1,y2], color = '#0000FF', label = "Avg Wind")
    #labeling
    ax.set_xlabel('date')
    ax.set_ylabel('Maximum Temperature, F')
    ax2.set_ylabel('Average Wind Speed, mph')
    ax2.yaxis.set_label_position('right')
    fig.legend([line1, line2], ['Max Temp', 'Avg Wind'], loc = 'lower left', bbox_to_anchor=(0.138,0.13))
    ax2.yaxis.tick_right()
    plt.title('Maximum Temperature and Average Wind Speed')
    plt.show()
    
def hist_graph():
    plt.figure()
    lst = []
    #access average wind speed
    for i in range(len(content)):
        split = content[i].split(',')
        lst.append(float(split[1]))
    #plot
    plt.hist(lst, bins= 30, range = [0.0,20.0], color = '#008000', edgecolor = 'k')
    plt.title('Histogram of average wind speed')
    plt.xlabel('Average Wind Speed, mph')
    plt.ylabel('Number of days')
    plt.show
    
def scatter_graph():
    plt.figure()
    #access min tempand avg wind speed
    for i in range(len(content)):
        split = content[i].split(',')
        x1 = int(split[5])
        y1 = float(split[1])
        #graph each point
        plt.plot(x1, y1, '.', color = 'k')
    plt.xlabel('Minimum Temperature, F')
    plt.ylabel('Average Wind Speed, mph')
    plt.title('Average Wind Speed vs Minimum Temperature')
    plt.show()
    
def highest_lowest():
    #FOR GRAPH 4
    hightemp = {'1':[],'2':[],'3':[],'4':[],'5':[],'6':[],'7':[],'8':[],'9':[],'10':[],'11':[],'12':[]}
    lowtemp = {'1':[],'2':[],'3':[],'4':[],'5':[],'6':[],'7':[],'8':[],'9':[],'10':[],'11':[],'12':[]}
    list_max = []
    list_min = []
    #high temp dict
    for i in range(len(content)):
        split = content[i].split(',')
        split2 = split[0].split('/')
        for i in hightemp:
            if split2[0] == i:
                hightemp[i].append(int(split[4]))
    #lowtemp dict
    for i in range(len(content)):
        split = content[i].split(',')
        split2 = split[0].split('/')
        for i in lowtemp:
            if split2[0] == i:
                lowtemp[i].append(int(split[5]))
    #finding highest of high
    for i in hightemp:
        list1 = hightemp[i]
        maximum = max(list1)
        list_max.append(int(maximum))
    #finding lowest of low
    for i in lowtemp:
        list1 = lowtemp[i]
        minimum = min(list1)
        list_min.append(int(minimum))
    return list_max, list_min
            
    
def bar_graph():
    plt.figure()
    avgdict = {'1':[],'2':[],'3':[],'4':[],'5':[],'6':[],'7':[],'8':[],'9':[],'10':[],'11':[],'12':[]}
    lst = []
    #get  avg temp
    for i in range(len(content)):
        split = content[i].split(',')
        split2 = split[0].split('/')
        for i in avgdict:
            if split2[0] == i:
                avgdict[i].append(split[3])
    months = list(avgdict.keys()) 
    #sum/average avg temps
    for i in avgdict:
        sum = 0
        length = 0
        list1 = avgdict[i]
        for j in list1:
            sum += int(j)
            length +=1
        avg = sum/length
        lst.append(avg)
    temps = lst
    plt.bar(months, temps, color = 'y')
    
    #low of low, high of high
    maxi, mini = highest_lowest()
    lt = [0,1,2,3,4,5,6,7,8,9,10,11]
    plt.plot(lt,maxi, color = '#FF0000', label = 'High T')
    plt.plot(lt,mini, color = '#0000FF', label = 'Low T')
    plt.ylabel('Average Temperature, F')
    plt.xlabel('Month')
    plt.title('Temperature by Month')
    plt.legend()
    plt.show()

#call each graph
line_graph()
hist_graph()
scatter_graph()
bar_graph()
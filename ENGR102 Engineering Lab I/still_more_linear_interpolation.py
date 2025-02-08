# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 3.16: Still More Linear Interpolation
# Date:         7 September 2022

#User inputs
print("Enter time 1:")
startTime = float(input())
print("Enter the x position of the object at time 1:")
xInit = float(input())
print("Enter the y position of the object at time 1:")
yInit = float(input())
print("Enter the z position of the object at time 1:")
zInit = float(input())

print("Enter time 2:")
endTime = float(input())
print("Enter the x position of the object at time 2:")
xFinal = float(input())
print("Enter the y position of the object at time 2:")
yFinal = float(input())
print("Enter the z position of the object at time 2:")
zFinal = float(input())

#Calculate interval between time points (5 points total, including endpoints)
interval = (endTime-startTime)/4

#Rate of change calculations
xRate = (xFinal-xInit)/(endTime-startTime)
yRate = (yFinal-yInit)/(endTime-startTime)
zRate = (zFinal-zInit)/(endTime-startTime)

#Perform linear interpolation at a particular time
time = startTime
x = xRate*(time-startTime)+xInit
y = yRate*(time-startTime)+yInit
z = zRate*(time-startTime)+zInit

#Print results
output = f"At time {time:.2f} seconds the object is at "
output += f"({x:.3f}, {y:.3f}, {z:.3f})"
print(output)

#Repeat calculations and output for a total of 5 times
time += interval
x = xRate*(time-startTime)+xInit
y = yRate*(time-startTime)+yInit
z = zRate*(time-startTime)+zInit

output = f"At time {time:.2f} seconds the object is at "
output += f"({x:.3f}, {y:.3f}, {z:.3f})"
print(output)

time += interval
x = xRate*(time-startTime)+xInit
y = yRate*(time-startTime)+yInit
z = zRate*(time-startTime)+zInit

output = f"At time {time:.2f} seconds the object is at "
output += f"({x:.3f}, {y:.3f}, {z:.3f})"
print(output)

time += interval
x = xRate*(time-startTime)+xInit
y = yRate*(time-startTime)+yInit
z = zRate*(time-startTime)+zInit

output = f"At time {time:.2f} seconds the object is at "
output += f"({x:.3f}, {y:.3f}, {z:.3f})"
print(output)

time += interval
x = xRate*(time-startTime)+xInit
y = yRate*(time-startTime)+yInit
z = zRate*(time-startTime)+zInit

output = f"At time {time:.2f} seconds the object is at "
output += f"({x:.3f}, {y:.3f}, {z:.3f})"
print(output)
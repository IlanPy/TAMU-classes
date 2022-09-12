# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 4: Activity #1
# Date:         12 September 2022

print("How much did you pay?", end =' ')
x = float(input())
print("How much did it cost?", end =' ')
y = float(input())
z=(x-y)*100
dollar=0
quarter=0
dime=0
penny=0
while(z>=100):
    z-=100
    dollar+=1
while(z>=25):
    z-=25
    quarter+=1
while(z>=10):
    z-=10
    dime+=1
while(z>=1):
    z-=1
    penny+=1

print(f"you received {x-y} in change. That is...")
if(dollar==1):
    print(f"{dollar} dollar")
elif dollar>1:
    print(f"{dollar} dollars")
if(quarter==1):
    print(f"{quarter} quarter")
elif quarter>1:
    print(f"{quarter} quarters")
if(dime==1):
    print(f"{dime} dime")
elif dime>1:
    print(f"{dime} dimes")
if(penny==1):
    print(f"{penny} penny")
elif penny>1:
    print(f"{penny} pennies")


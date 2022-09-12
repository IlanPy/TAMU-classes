# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 4.13: Make change
# Date:         12 September 2022

#Ask user for payment and cost
print("How much did you pay?")
payment = float(input())
print("How much did it cost?")
cost = float(input())

#Calculate change and coins to return
change = payment - cost
quarters = change*100 // 25
remainder = change*100 % 25
dimes = remainder // 10
remainder = remainder % 10
nickels = remainder // 5
remainder = remainder % 5

if remainder < 1 and 1 - remainder <= 0.01:
    pennies = 1
elif remainder < 1:
    pennies = 0
else:
    pennies = remainder

#Print results
print(f"You received ${change:.2f} in change. That is...")

#Print number of quarters
if quarters == 1:
    print(f"{quarters:.0f} quarter")
elif quarters > 0:
    print(f"{quarters:.0f} quarters")

#Print number of dimes
if dimes == 1:
    print(f"{dimes:.0f} dime")
elif dimes > 0:
    print(f"{dimes:.0f} dimes")

#Print number of nickels
if nickels == 1:
    print(f"{nickels:.0f} nickel")
elif nickels > 0:
    print(f"{nickels:.0f} nickels")

#Print number of pennies
if pennies == 1:
    print(f"{pennies:.0f} penny")
elif pennies > 0:
    print(f"{pennies:.0f} pennies")
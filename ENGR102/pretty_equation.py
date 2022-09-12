# By submitting this assignment, I agree to the following:
#   "Aggies do not lie, cheat, or steal, or tolerate those who do."
#   "I have not given or received any unauthorized aid on this assignment."
#
# Names:        Jordan Rivas
#               Ilan Sela
#               Robert Stacks
#               Dave Wright
# Section:      501
# Assignment:   LAB 4: Activity #2
# Date:         12 September 2022

#input
print("Please enter the coefficient A:",end=" ")
a = int(input())
print("Please enter the coefficient B:",end=" ")
b = int(input())
print("Please enter the coefficient C:",end=" ")
c = int(input())

#exceptions and formatting
if a==-1:
    a = "- "
elif a<0:
    a = f"- {abs(a)}"
if b==-1:
    b = "- "
elif b<0:
    b = f"- {abs(b)}"
else:
    b = f"+ {b}"
if c<0:
    c = f"- {abs(c)}"
else:
    c = f"+ {c}"

#output
if(a==0):
    print(f"The quadratic equation is {b}x {c} = 0")
elif(b==0):
    print(f"The quadratic equation is {a}x^2 {c} = 0")
elif(c==0):
    print(f"The quadratic equation is {a}x^2 {b}x = 0")
else:
    print(f"The quadratic equation is {a}x^2 {b}x {c} = 0")
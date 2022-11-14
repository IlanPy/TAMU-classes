# As a team, we have gone through all required sections of the  
# tutorial, and each team member understands the material 
import numpy as np

A = np.arrange(12).reshape(3,4)
B = np.arrange(8).reshape(4,2)
C = np.arrange(6).reshape(2,3)

print(f'A = {A}\n\nB = {B}\n\n C = {C}\n')

D = A @ B @ C

print(f'D = {D}\n')

DT = np.transpose(D)

print(f'D^T = {DT}\n')

E = np.sqrt(D/DT)

print(f'E = {E}')
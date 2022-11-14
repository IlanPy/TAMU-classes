# As a team, we have gone through all required sections of the  
# tutorial, and each team member understands the material 
import numpy as np

A = np.arange(12).reshape(3,4)
B = np.arange(8).reshape(4,2)
C = np.arange(6).reshape(2,3)

print(f'A = {A}\n\nB = {B}\n\n C = {C}\n')

D = A @ B @ C

print(f'D = {D}\n')

DT = np.transpose(D)

print(f'D^T = {DT}\n')

E = np.sqrt(D/2)

print(f'E = {E}')
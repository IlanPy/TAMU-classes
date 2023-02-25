import math
from matplotlib import pyplot as plt
import numpy as np

x = np.linspace(0.00000000000000000001,10,500)

def f(x):
    return ((math.log(x)*math.sinh(x))/((math.e)**x))
f2 = np.vectorize(f)
plt.plot(x,f2(x))
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('f(x) = ln(x)*sinh(x)/e^x')
plt.show()

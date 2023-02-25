from matplotlib import pyplot as plt
import matplotlib as mpl
from datetime import datetime
import matplotlib.dates as mdates

x_vals = [0.000,0.00200,0.00600,0.0120,0.0180,0.0240]
y_vals = [0.000,0.067,0.572,2.291,5.047,9.041]

fig,ax = plt.subplots()
ax.plot(x_vals,y_vals)
ax.scatter(x_vals,y_vals)

plt.xlabel('Distance (m)')
plt.ylabel('Velocity (m/s)')
plt.title('Velocity (m/s) vs. Distance (m)')
plt.show()

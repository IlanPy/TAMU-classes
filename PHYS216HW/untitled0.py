from matplotlib import pyplot as plt
import matplotlib as mpl
from datetime import datetime
import matplotlib.dates as mdates
import numpy as np

x_vals = ['0:00:00','0:59:12','2:01:46','2:58:55','3:47:01','4:13:00','5:36:17']
y_vals = [102.0,157.8,217.6,264.1,315.2,341.7,420.3]
myFmt = [datetime.strptime(item,'%H:%M:%S') for item in x_vals]

fig,ax = plt.subplots()
ax.plot(myFmt,y_vals)
ax.scatter(myFmt,y_vals)
ax.xaxis.set_major_formatter(mdates.DateFormatter('%H:%M:%S',))
plt.xlabel('Clock time (hr:min:sec)')
plt.ylabel('Odometer reading (mi)')
plt.title('Odometer reading (mi) vs. Clock time (hr:min:sec)')
plt.show()

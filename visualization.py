import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
# files used for visualization
fs = open("steps.txt", "r")
f3d = open("3d.txt", "r")
fsLines = fs.readlines()
f3dLines = f3d.readlines()

# arrays used for visualization
xx, yy, zz = ([] for i in range(3))
X, Y, Z = ([[] for i in range(50)] for i in range(3))

# read path from steps.txt and put into arrays xx, yy, zz
for line in fsLines:
    line = [float(x.rstrip('\n')) for x in line.split(",")]
    xx.append(line[0])
    yy.append(line[1])
    zz.append(line[2])

# read values from 3d.txt and put into arrays X, Y, Z
for i in range(50):
    for j in range(50):
        line = [float(x.rstrip('\n')) for x in f3dLines[i*50+j].split(",")]
        X[i].append(line[0])
        Y[i].append(line[1])
        Z[i].append(line[2])

# Visualization starts here
fig = plt.figure(figsize=plt.figaspect(2.))
fig.suptitle('Visualization')
# Function visualization with shortest path
ax = fig.add_subplot(2, 1, 1, projection='3d')
ax.plot_surface(np.array(X), np.array(Y), np.array(Z), rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.plot(xx, yy, zz, 'ro', alpha=0.5)
ax.set_title('Function with path (red) to local minima')

# Number of iterations against fx value
ax = fig.add_subplot(2, 1, 2)
ax.plot(range(len(zz)), zz)

ax.set(xlabel='Number of iterations', ylabel='Function Values f(x)',
       title='Function Values during Optimization')
ax.grid()
plt.show()

fs.close()
f3d.close()

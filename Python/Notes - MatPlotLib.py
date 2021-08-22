--------------------------------------------MATPLOTLIB

import matplotlib.pyplot as plt

                                    PYPLOT

plt.show()                               # Displays the plot.
%matplotlib inline                       # Displays plots automatically.


plt.plot(X,Y)                            # Plots X against Y (arrays).
linestyle,color,marker,drawstyle,label   # ...arguments of plt.plot().
-  --  -.  :                             # ...line styles.
.  ,  o  v  ^  <  >  1  2  3  4          # ...marker styles.
s  p  *  h  H  +  x  D  d  |  _          # ...marker styles.

xlim,xticks,xticklabels,legend           # ...methods of plt.


plt.scatter(X,Y)                         # Plots points with coordinates X,Y.


imshow(MAT, cmap=)                       # Plots an image from a matrix of values.


my_fig, axes = plt.subplots(V,H)         # Creates a figure of VxH subplots (H=horizontal, V=vertical).
my_fig = plt.figure()                    # Creates a figure object.
axis = fig.add_subplot(V,H,N)            # Assigns the N-th subplot in VxH figure.

set_xlim,set_xticks,set_xticklabels      # ...methods of axes in subplots, x <--> y.
set_xlabel,set_title                     # ...methods of axes in subplots, x <--> y.
text(X,Y, 'TEXT', family=, fontsize=)    # ...method of axes, adds text to a figure at coordinates X,Y.
arrow(X1,Y1,X2,Y2)                       # ...method of axes, draws an arrow.

axes[V,H].plot()                         # Assignes a plot into the [V,H] subfigure of my_fig.
fig.subplots_adjust()                    # Adjusts space between subplots.
left=0, bottom=0, right=1, top=1         # ...arguments of subplots_adjust().
wspace=0.5, hspace=0.5                   # ...arguments of subplots_adjust().


my_fig.savefig('file_name.svg')          # Saves my_fig to a file. 
plt.savefig('*.png',dpi=)                # Saves active figure into '*.png', different extension possible.
bbox_inches,fname,format                 # ...arguments of plt.savefig().
facecolot,edgecolor                      # ...arguments of plt.savefig().


matplotlib.matches                       # Contains geometric shapes e.g. circle, rectangle etc.
#username - Pawan8576
#Topic - Display anything inside a heart
#date- 13/10/2023

import pylab 
import numpy as np 

# Width of heart 
Xaxis = np.linspace(-2, 2, 
					100000) 

# Setting upper y 
Y1axis = np.sqrt(1 -
		(abs(Xaxis) - 1) **2) 

# Setting -y 
Y2axis = -3 * np.sqrt(1 -
		(abs(Xaxis) / 2) **0.5) 

# Adjust colour for upper part 
# of herat 
pylab.fill_between(Xaxis, Y1axis, 
				color = 'red') 

# Adjust colour for lower part 
# of heart 
pylab.fill_between(Xaxis, Y2axis, 
				color = 'red') 


pylab.xlim([-2.5, 2.5]) 
pylab.axis("off") 

# Driver Code 
text = "Geeksforgeeks"

pylab.text(0, -0.4, text, 
		fontsize = 24, 
		fontweight = 'bold', 
		color = 'white', 
		horizontalalignment = 'center')

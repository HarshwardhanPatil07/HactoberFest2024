# from numpy import*
from array import*
arr = array('i',[])
#th

l= int(input('Enter the Len. '))

for i in range(l):
    n=int(input('Enter the values '))
    arr.append(n)

print(arr)

max=arr[0]

for i in range(len(arr)):
    if max<arr[i]:
        
        max=arr[i]
#

print(max)


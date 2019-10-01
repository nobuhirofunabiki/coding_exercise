import numpy as np
import math

cx = np.arange(0, 10, 1)
cy = [math.sin(ix/5.0)*ix/2.0 for ix in cx]
print(cx)
print(cy)

print(len(cx))
print(cx[len(cx)-1])


list1 = [4, 2, 1, 3, 9, 7, 5]
index_min = list1.index(min(list1))
print(index_min)
print(list1[index_min])


list2 = [0, 1, 2]
list2.append(3)
print(list2)


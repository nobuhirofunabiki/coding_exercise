import pandas
import numpy as np
import math

# Simple example 1
df = pandas.DataFrame([
  ["0001", "John", "Engineer"],
  ["0002", "Lily", "Sales"]],
  columns=['id', 'name', 'job'])
df.to_csv("output/employee.csv")


# Simple example 2
cx = np.arange(0, 50, 0.1)
cy = [math.sin(ix / 5.0) * ix / 2.0 for ix in cx]
df2 = pandas.DataFrame([cx, cy])
df2.to_csv("output/sine_curve.csv")

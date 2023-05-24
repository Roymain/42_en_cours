import numpy as np 
import pandas as pd

thetas = pd.read_csv('thetas.csv')

t0 = thetas["theta0"]
t1 = thetas["theta1"]

df = pd.read_csv('data.csv')
dataset = df.to_numpy()
XX = df["km"]
YY = df["price"]


minX = min(XX)
maxX = max(XX)
minY = min(YY)
maxY = max(YY)

mileage_input = float(input("Enter a mileage: "))

normalized = (mileage_input - minX) / (maxX - minX)

pnorm = t0 + t1 * normalized

price = (pnorm.item()) * (maxY - minY) + minY

print("Predicted price: ", price)
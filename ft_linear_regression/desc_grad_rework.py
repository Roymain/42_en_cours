import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd

df = pd.read_csv('data.csv')
dataset = df.to_numpy()

thetas = pd.read_csv('thetas.csv')

XX = df["km"]
YY = df["price"]


#ok
def normalization(XX, YY):
	X = []
	y = []
	minX = min(XX)
	maxX = max(XX)
	for i in range(len(XX)):
		X.append( (XX[i] - minX) / (maxX - minX) )
	minY = min(YY)
	maxY = max(YY)
	for i in range(len(YY)):
		y.append( (YY[i] - minY) / (maxY - minY) )
	return (X, y)

#normalement ok
def	lossFunction(t0, t1, mileages, prices):
	loss = 0.0
	for mileage, price in zip(mileages, prices):
		loss += (price - (t1 * mileage + t0)) ** 2
	return ((1 / (2 * XX.size)) * loss)

def	normalizeElem(list, elem):
	return ((elem - min(list)) / (max(list) - min(list)))

def	denormalizeElem(list, elem):
	return ((elem * (max(list) - min(list))) + min(list))

def train(X, y, learning_rate, num_iterations):
    t0 = thetas["theta0"]
    t1 = thetas["theta1"]
    costs = []  # Liste pour stocker les coûts à chaque itération
    
    for i in range(num_iterations):
        # Mise à jour des paramètres t0 et t1
        
        # Calcul du gradient par rapport à t0
        gradient_t0 = 0
        for mileage, price in zip(X, y):
            gradient_t0 += (t1 * mileage + t0 - price)
        
        # Calcul du gradient par rapport à t1
        gradient_t1 = 0
        for mileage, price in zip(X, y):
            gradient_t1 += (t1 * mileage + t0 - price) * mileage
        
        # Mise à jour des paramètres
        t0 = t0 - (learning_rate * gradient_t0) / XX.size
        t1 = t1 - (learning_rate * gradient_t1) / XX.size
        
        # Calcul du coût et ajout à la liste
        cost = lossFunction(t0, t1, X, y)
        costs.append(cost)
    
    return t0, t1, costs


X, y = normalization(XX, YY)

t0 , t1 , costs = train(X, y, 0.1 , 100)

thetas['theta0'] = t0
thetas['theta1'] = t1
thetas.to_csv('thetas.csv', index=False)


XX = XX.tolist()

fig, axs = plt.subplots(2, 1)
axs[0].scatter(X, y)


ypoints = np.array([t0 + t1 * 0 , t0 + t1 * 1])
xpoints = np.array([0, 1])

axs[0].plot(xpoints, ypoints, color="red")

axs[0].set_xlabel("Kilometers")
axs[0].set_ylabel("Price")
axs[0].set_title("Normalized graphic")




axs[1].plot(xpoints, ypoints, color="red")

axs[1].set_xlabel("Kilometers")
axs[1].set_ylabel("Price")
axs[1].set_title("Normalized graphic")


		
plt.show()


def	boldDriver(loss, lossHistory, t0, t1, dt0, dt1, learningRate, length):
	newLearningRate = learningRate
	if len(lossHistory) > 1:
		#print("::::", loss)
		#print("????", lossHistory)
		if loss >= lossHistory[-1]:
			t0 += dt0 / length * learningRate
			t1 += dt1 / length * learningRate
			newLearningRate *=  0.5
		else:
			newLearningRate *= 1.05
	return (t0, t1, newLearningRate)


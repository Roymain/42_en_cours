import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd

df = pd.read_csv('data.csv')
dataset = df.to_numpy()

thetas = pd.read_csv('thetas.csv')

XX = df["km"]
YY = df["price"]
print("dep = ", XX[0])
print("indep = ", YY[0])
print("len = ", XX.size)

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

t0 , t1 , costs = train(X, y, 0.1 , 1000)

thetas['theta0'] = t0
thetas['theta1'] = t1
thetas.to_csv('thetas.csv', index=False)



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




# def init(X):
#     W = np.random.randn(1)
#     b = np.random.randn(1)
#     print('dimensions de X:', W)
#     print('dimensions de y:', W.shape)
#     return (W, b)

# def model(X, W, b):
#     Z = X * W + b            #vecteur     Z = X.W+b
#     A = 1 / (1 + np.exp(-Z))  #fction d activation  
#     return (A)

# def	log_loss(b, W, mileages, prices):
# 	loss = 0.0
# 	for i in range(23):
# 		loss += (y[i] - (b + mileages[i] * W)) ** 2      #creation de l indice de precision
# 	return (loss / len(mileages))

# def gradients(A, X, y):
#     return (dW, db)

# def update(dW, db, W, b, learning_rate):
#     W = W - learning_rate * dW
#     b = b - learning_rate * db
#     return (W, b)

# def artificial_neuron(X, y, learning_rate = 0.01, nb_iter = 10):
#     W, b = init(X)
#     dt0 = 0
#     dt1 = 0
#     Loss = []
#     print("miaou")
#     for i in range(nb_iter):
#         A = model(X, W, b)
#         Loss.append(log_loss(b, W, X, y))
#         for i in range(23):
#             dt0 += (W * X + b) - y
#             dt1 += ((W * X + b) - y) * X
#         W, b = update(dt0, dt1, W, b, learning_rate)

#     print("loss = " , Loss)
#     plt.plot(Loss)
#     plt.show()


# artificial_neuron(X, y)




# X, y = make_blobs(n_samples=100, n_features=2, centers=2, random_state=0)
# y = y.reshape((y.shape[0], 1))

# print('dimensions de X:', X.shape)
# print('dimensions de y:', y.shape)

# plt.scatter(X[:,0], X[:, 1], c=y, cmap='summer')
# plt.show()
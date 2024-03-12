import numpy as np
import pandas as pd
import math

df = pd.read_csv('./datasets/dataset_test.csv')

dataset = df.to_numpy()


print(df.columns)




def std(dataset, MEAN, col_name):
	i = 0
	summ = 0
	for value in df[col_name]:
		if np.isnan(value):
			continue
		else:
			i += 1
			summ += (value - MEAN) ** 2
	summ = summ / i
	return math.sqrt(summ)

for col_name in df.columns:
	STD = 0
	nb = 0
	total = 0
	tmax = - np.inf
	tmin = np.inf
	for value in df[col_name]:
		if type(value) is str:
			break
		if np.isnan(value):
			continue
		else:
			nb += 1
			total += value
			if value > tmax:
				tmax = value
			if value < tmin:
				tmin = value
	if nb == 0:
		continue
	else:
		MEAN = total / nb
		STD = std(df, MEAN, col_name)
		print(col_name, ": STD = ", STD, ", MEAN= ", MEAN,  ", Min= ", tmin, ", Max= ", tmax)
		print(np.std(df[col_name]))


# TODO foutre ca dans un tableau, et executable comme dans le sujet
# + autres script :
		# histogram => celui avec le plus petit ecart type
		# 

# import pandas as pd

# # Créer un DataFrame de test
# data = pd.DataFrame({'Colonne1': [1, 2, 3], 'Colonne2': ['a', 'b', 'c']})

# # Vérifier si les colonnes sont numériques
# colonnes_numeriques = data.select_dtypes(include='number').columns
# print("Colonnes numériques :", colonnes_numeriques)

# # Vérifier si les colonnes sont alphabétiques
# colonnes_alphabetiques = data.select_dtypes(include='object').columns
# print("Colonnes alphabétiques :", colonnes_alphabetiques)
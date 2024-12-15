import pandas as pd
import numpy as np
import seaborn as sbn
import matplotlib
import matplotlib.pyplot as plt

dic = { 
    "coluna 1": ['linha1', 'linha2', 'linha3'],
    "coluna 2": ['linha1', 'linha2', 'linha3']    
}

#table = pd.DataFrame(dic)
# print(table.head())

df = pd.read_csv('https://raw.githubusercontent.com/fivethirtyeight/data/master/alcohol-consumption/drinks.csv')

#print(df.head())
#print(df.shape)
#print(df.info)
#print(df.describe())
#print(df.isnull().sum())
#print(df.isnull().sum() / len(df) * 100)
#print(df['country'][:10])
#print(df['beer_servings'].value_counts())
#print(df['wine_servings'].value_counts())
#print(df['wine_servings'].value_counts().sort_values())
#print(df[df['country'] == 'Brazil'])
#print(df['total_litres_of_pure_alcohol'])

consumo = df[df['total_litres_of_pure_alcohol'] >= 7] 
#print(consumo.head(10))
sbn.countplot(data=consumo, x='total_litres_of_pure_alcohol')
plt.ylabel('Porcentagem de consumo')
plt.xlabel('Total litres of Pure Alcohol')
#plt.show()

#print(consumo.describe())
print(df.describe())

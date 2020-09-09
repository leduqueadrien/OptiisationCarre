# D:\Projet\optimisationNbCase\AlgoApprentissage\Affichage
import numpy as np
import matplotlib.pyplot as plt

longueur = np.loadtxt("Longueur.txt")   # X (abscisse)
resultat = np.loadtxt("Resultat.txt")   # 

resultat = resultat[:,0]

plt.plot(longueur, resultat)

plt . show ()
# D:\Projet\optimisationNbCase\AlgoApprentissage\Affichage
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D


longueur = np.loadtxt("Longueur.txt")   # X (abscisse)
hauteur = np.loadtxt("Hauteur.txt")     # Y (ordonnee)
resultat = np.loadtxt("Resultat.txt")   # 

longueur, hauteur = np.meshgrid (longueur, hauteur)


fig = plt . figure ()
ax = Axes3D ( fig )
ax . plot_surface (longueur, hauteur, resultat , rstride = 1 , cstride = 1 , cmap = cm . viridis )

plt . show ()
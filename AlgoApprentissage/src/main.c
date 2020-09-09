
#include "Optimisation/optimisation.h"
#include "Network/network.h"
#include "Matrice/matrice.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	// Test affichage fonction 3D
	double borneInf = 100;
	double borneSup = 500;
	double precision = 5;
	int n = (borneSup-borneInf)/precision;
	Vecteur_t * vectLongueur = CreerVecteur(n, 1);
	Vecteur_t * vectHauteur = CreerVecteur(n, 1);
	Matrice_t * matResultat = CreerMatrice(n, n);
	int nbCase = 11;
	double longueur;
	double hauteur;

	for (int i=0; i<n; i++) {
		double valeur = borneInf + i*precision;
		SetValeurVecteur(valeur, *vectLongueur, i);
		SetValeurVecteur(valeur, *vectHauteur, i);	
	}

	for (int i=0; i<n; i++) {
		hauteur = GetValeurVecteur(*vectHauteur, i);
		for (int j=0; j<n; j++) {
			longueur = GetValeurVecteur(*vectLongueur, j);
			SetValeurMatrice(ResoudreOptimisationCarre(longueur, hauteur, nbCase), *matResultat, i, j);
		}
	}


	EcrireVecteurFichier("Affichage/Longueur.txt", *vectLongueur, " ");
	EcrireVecteurFichier("Affichage/Hauteur.txt", *vectHauteur, " ");
	EcrireMatriceFichier("Affichage/Resultat.txt", *matResultat, " ");

	LibererVecteur(vectHauteur);
	LibererVecteur(vectLongueur);
	LibererMatrice(matResultat);

	return 0;
}
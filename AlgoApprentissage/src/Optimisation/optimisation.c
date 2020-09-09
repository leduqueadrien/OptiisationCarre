
#include "optimisation.h"
#include <stdlib.h>
#include <stdio.h>
#include "../Aleatoire/aleatoire.h"


Fonction_t * CreerFonction() {
	Fonction_t * fonction = (Fonction_t *)malloc(sizeof(Fonction_t));
	return fonction;
}

void ParametrerFonctionFichier(char * nomFichier, Fonction_t * fonction) {
	FILE * file = fopen(nomFichier, "r");
	char * ligne;
	if( file != NULL) {
		while (feof(file) == 0) {
			;
		}
	}
}

void InitialisationFonction(Fonction_t * fonction, int borneInfNbCase, int borneSupNbCase, double borneInfFenetre, double borneSupFenetre) {
	
	((*fonction).borneInfNbCase) = borneInfNbCase;
	((*fonction).borneSupNbCase) = borneSupNbCase;
	((*fonction).borneInfFenetre) = borneInfFenetre;
	((*fonction).borneSupFenetre) = borneSupFenetre;

	(*fonction).nbCase = 0;
	(*fonction).longueur = 0;
	(*fonction).hauteur = 0;
	(*fonction).tailleCase = 0;
	
}


void GenererEntreeFoncton(Fonction_t * fonction) {
	(*fonction).nbCase = GenererIntAleatoire((*fonction).borneInfNbCase, (*fonction).borneSupNbCase);
	(*fonction).longueur = GenererDoubleAleatoire((*fonction).borneInfFenetre, (*fonction).borneSupFenetre);
	(*fonction).hauteur = GenererDoubleAleatoire((*fonction).borneInfFenetre, (*fonction).borneSupFenetre);
	
}

void ResoudreFonction(Fonction_t * fonction) {
	(*fonction).tailleCase = ResoudreOptimisationCarre((*fonction).longueur, (*fonction).hauteur, (*fonction).nbCase);
}

double ResoudreOptimisationCarre(double longueur, double hauteur, int nbCase) {
	int terminer = 0;

	int nbColumns = nbCase;
	int nbLines   = 1;

	double sImX = 0;
	double sImY = 0;

	double sImNouv = 0;
	double sImAncien = 0;

	while (terminer == 0) {

		sImX = longueur / nbColumns;
		sImY = hauteur / nbLines;
		sImNouv = (sImX < sImY)? sImX : sImY;

		if (sImNouv < sImAncien) {
			terminer = 1;

			// on remet la bonne valeur de colonnes correspondante a literation precedente (donc la bonne valeur de sizeSideIm)
			(nbColumns)++;

		} else {
			sImAncien = sImNouv;
			(nbColumns)--;
			
			if (nbColumns == 0) {
				terminer = 1;
				(nbColumns)++;
			}
		}

		nbLines = nbCase / nbColumns;
		if (nbCase % nbColumns != 0) {
			(nbLines) ++;
		}
	}
	return sImAncien;
}


void AfficherFoncrion(Fonction_t * fonction) {
	printf("f(%d, %.2lf, %.2lf) = %.2lf\n", (*fonction).nbCase, (*fonction).longueur, (*fonction).hauteur, (*fonction).tailleCase);
}


void LibererFonction(Fonction_t * fonction) {
	free(fonction);
}
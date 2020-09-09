
#include "network.h"
#include "../Optimisation/optimisation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "../Matrice/matrice.h"		//Deja inclu dans le .h


int InitialiserNetwork() {
	int codeErreur = 0;
	int tailleEntree = 0;
	int tailleSortie = 0;
	int nbCoucheCachee = 0;


	printf("Taille du vecteur d'entree : ");
	scanf("%d", &tailleEntree);

	printf("Taille du vecteur de sortie : ");
	scanf("%d", &tailleSortie);

	printf("Nombre couche cachee (on ne compte pas la couche final) : ");
	scanf("%d", &nbCoucheCachee);

	NETWORK.tailleEntree = tailleEntree;
	NETWORK.tailleSortie = tailleSortie;
	NETWORK.nbCoucheCachee = nbCoucheCachee;
	NETWORK.tabCouche = (Couche_t **)malloc((nbCoucheCachee+1) * sizeof(Couche_t *));

	int cpt = 0;
	while (cpt < nbCoucheCachee && codeErreur == 0) {
		char type [100];
		
		printf("Fonction d'activation : ");
		scanf("%s", type);

		// Si la chaine commence par le symbole #, c'est que la ligne etait un commentaire
		if (*type != '#') {
			printf("Taille du vecteur d'entree de la couche n°%d : ", cpt);
			scanf("%d", &tailleEntree);

			printf("Taille du vecteur de sortie de la couche cachee n°%d : ", cpt);
			scanf("%d", &tailleSortie);

			*(NETWORK.tabCouche+cpt) = CreerCouche(tailleEntree, tailleSortie, type);
			if (*(NETWORK.tabCouche+cpt) == NULL)
				codeErreur = 0;
			
			cpt++;
		}

	}
	// Creation derniere couche
	*(NETWORK.tabCouche+cpt) = CreerCouche(tailleSortie, NETWORK.tailleSortie, "identite");
	
	return codeErreur;
}

Couche_t * CreerCouche(int tailleEntree, int tailleSortie, char * type) {
	Couche_t * couche = (Couche_t *)malloc(sizeof(Couche_t));
	(*couche).tailleEntree = tailleEntree;
	(*couche).tailleSortie = tailleSortie;
	(*couche).W = CreerMatrice(tailleSortie, tailleEntree);
	(*couche).vectEntree = NULL;
	(*couche).vectSortie = NULL;
	
	if (!strcmp(type, "identite")) {
		(*couche).pActivation = &identite;
	}

	if (!strcmp(type, "sigmoide")) {
		(*couche).pActivation = &sigmoide;
	}

	return couche;
}

void InitialiserNetworkAlea(double borneInf, double borneSup) {
	for (int k=0; k<NETWORK.nbCoucheCachee+1; k++) {
		Matrice_t * matrice = (**(NETWORK.tabCouche+k)).W;
		RemplirMatriceAleatoire(*matrice, borneInf, borneSup);
	}
}

/* Amelioration : Parametrage dans une autre fonction et lecture depuis un fichier de configuration */
void Apprentissage() {
	// Creation du reseau
	InitialiserNetwork();
	// Initialisation aleatoire du reseau
	InitialiserNetworkAlea(100, 100);
	// Creation du vecteur d'entree
	Vecteur_t * vectEntree = CreerVecteur(3, 0);
	// Creation de la fonction a optimiser
	Fonction_t * fonction = CreerFonction();
	// Initialisation des parametre de la fonction
	InitialisationFonction(fonction, 1, 100, 100, 1000);
	int continuer = 1;

	while (continuer) {
		// Generation d'une nouvelle entree
		GenererEntreeFoncton(fonction);
		// Mise a jour du vecteur d'entree du reseau neuronal
		SetValeurVecteur((*fonction).nbCase, *vectEntree, 0);
		SetValeurVecteur((*fonction).longueur, *vectEntree, 1);
		SetValeurVecteur((*fonction).hauteur, *vectEntree, 2);


	}

}


void LibererCouche(Couche_t * couche) {
	LibererMatrice((*couche).W);
	free(couche);
	couche = NULL;
}

void LibererNetwork() {
	int nbCouche = NETWORK.nbCoucheCachee+1;
	for (int k=0; k<nbCouche; k++)
		LibererCouche(*(NETWORK.tabCouche+k));
	free(NETWORK.tabCouche);
}



void AfficherCouche(Couche_t * couche) {
	printf("Taille du vecteur d'entree : %d\n", (*couche).tailleEntree);
	printf("Taille du vecteur de sortie : %d\n", (*couche).tailleSortie);
	printf("Matrice des poids :\n");
	AfficherMatrice(*(*couche).W);
	printf("\n");
}

void AfficherNetwork() {
	int nbCoucheCachee = NETWORK.nbCoucheCachee;
	printf("\n");
	for (int k=0; k<nbCoucheCachee; k++) {
		printf("COUCHE CACHEE N°%d : \n", k+1);
		AfficherCouche(*(NETWORK.tabCouche+k));
	}
	printf("COUCHE DE SORTIE : \n");
	AfficherCouche(*(NETWORK.tabCouche+nbCoucheCachee));
}



double identite(double x, int derive) {
	if (derive == 0)
		return x;
	else
		return 1;
}


double sigmoide(double x, int derive) {
	if (derive == 0)
		return 1/(1+exp(-100*x));
	else
		return sigmoide(x, 0) * sigmoide(-x, 0);
}

double quadratique(double x, int derive) {
	if (derive == 0)
		return pow(x, 2);
	else
		return 2*x;
}


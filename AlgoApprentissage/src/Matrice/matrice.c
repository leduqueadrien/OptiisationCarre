
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "matrice.h"
#include "../Aleatoire/aleatoire.h"


Matrice_t * CreerMatrice(int n, int p) {
	Matrice_t * matrice = (Matrice_t *)malloc(sizeof(Matrice_t));
	if (matrice != NULL) {
		(*matrice).n = n;
		(*matrice).p = p;
		(*matrice).M = (double *)malloc(n*p * sizeof(double));
	} else {
		printf("Un probleme d'allocation memoire est survenue");
	}
	return matrice;
}

Vecteur_t * CreerVecteur(int n, int enColonne) {
	Vecteur_t * vecteur = (Vecteur_t *)malloc(sizeof(Vecteur_t));
	if (vecteur != NULL) {
		(*vecteur).n = n;
		(*vecteur).enColonne = enColonne;
		(*vecteur).V = (double *)malloc(n*sizeof(double));
	} else {
		printf("Un probleme d'allocation memoire est survenue");
	}
	return vecteur;
}


int RedimensionnerMatrice(Matrice_t  * M, int n, int p) {
	(*M).n = n;
	(*M).p = p;
	
	if ((*M).M != NULL)
		free((*M).M);

	(*M).M = NULL;
	(*M).M = malloc(n*p * sizeof(double));

	if ((*M).M == NULL) {
		printf("Un probleme d'allocation est survenue pendant le redimensionnement");
		return 1;
	} else {
		return 0;
	}
}

int RedimensionnerVecteur(Vecteur_t * V, int n) {
	(*V).n = n;

	if ((*V).V != NULL)
		free((*V).V);
	
	(*V).V = NULL;
	(*V).V = malloc(n * sizeof(double));

	if ((*V).V == NULL) {
		printf("Un probleme d'allocation est survenue pendant le redimensionnement");
		return 1;
	} else {
		return 0;
	}
}



double GetValeurMatrice(Matrice_t M, int i, int j) {
	int n = M.n;
	return *(M.M + i*n + j);
}

double GetValeurVecteur(Vecteur_t V, int i) {
	return *(V.V + i);
}

void SetValeurMatrice(double valeur, Matrice_t M, int i, int j) {
	int n = M.n;
	*(M.M + i*n + j) = valeur;
}

void SetValeurVecteur(double valeur, Vecteur_t V, int i) {
	*(V.V + i) = valeur;
}



void RemplirMatriceAleatoire(Matrice_t M, double borneInf, double borneSup) {
	for (int i=0; i<M.n; i++)
		for (int j=0; j<M.p; j++)
			SetValeurMatrice(GenererDoubleAleatoire(borneInf, borneSup), M, i, j);
}

void RemplirVecteurAleatoire(Vecteur_t V, double borneInf, double borneSup) {
	for (int i=0; i<V.n; i++)
		SetValeurVecteur(GenererDoubleAleatoire(borneInf, borneSup), V, i);
}

void RemplireValeurMatrice(Matrice_t M, double valeur) {
	for (int i=0; i<M.n; i++)
		for (int j=0; j<M.p; j++)
			SetValeurMatrice(valeur, M, i, j);
}

void RemplireValeurVecteur(Vecteur_t V, double valeur) {
	for (int i=0; i<V.n; i++)
			SetValeurVecteur(valeur, V, i);
}



int TransposerMatrice(Matrice_t M, Matrice_t * R) {
	int code = 0;
	if ((*R).n != M.p || (*R).p != M.n || (*R).M == NULL) {
		int code = RedimensionnerMatrice(R, M.p, M.n);
		if (code == 1)
			return code;
	}

	for (int i=0; i<M.n; i++)
		for (int j=0; j<M.p; j++)
			SetValeurMatrice(GetValeurMatrice(M, i, j), *R, j, i);

	return code;
}

void TransposerVecteur(Vecteur_t * V) {
	if ((*V).enColonne == 1)
		(*V).enColonne = 0;
	else
		(*V).enColonne = 1;
}


int ProduitMM(Matrice_t A, Matrice_t B, Matrice_t * R) {
	if (A.p == B.n) {

		if ((*R).n != A.n || (*R).p != B.p || (*R).M == NULL) {
			int code = RedimensionnerMatrice(R, A.n, B.p);
			if (code == 1)
				return code;
		}

		for (int i=0; i<A.n; i++) {
			for (int j=0; j<B.p; j++) {
				double somme = 0;
				for (int k=0; k<A.p; k++)
					somme += GetValeurMatrice(A, i, k) * GetValeurMatrice(B, k, j);
				SetValeurMatrice(somme, *R, i, j);
			}
		}
		return 0;
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
		return 2;
	}
}

int ProduitMTM(Matrice_t A, Matrice_t B, Matrice_t * R) {

	if (A.n == B.n) {

		if ((*R).n != A.p || (*R).p != B.p || (*R).M == NULL) {
			int code = RedimensionnerMatrice(R, A.p, B.p);
			if (code == 1)
				return 1;
		}

		for (int i=0; i<A.p; i++) {
			for (int j=0; j<B.p; j++) {
				double somme = 0;
				for (int k=0; k<A.n; k++)
					somme += GetValeurMatrice(A, k, i) * GetValeurMatrice(B, k, j);
				SetValeurMatrice(somme, *R, i, j);
			}
		}
		return 0;
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
		return 2;
	}
}

int ProduitMMT(Matrice_t A, Matrice_t B, Matrice_t * R) {
	if (A.p == B.p) {
		if ((*R).n != A.n || (*R).p != B.n || (*R).M == NULL) {
			int code = RedimensionnerMatrice(R, A.n, B.n);
			if (code == 1)
				return 1;
		}

		for (int i=0; i<A.n; i++) {
			for (int j=0; j<B.n; j++) {
				double somme = 0;
				for (int k=0; k<A.p; k++)
					somme += GetValeurMatrice(A, i, k) * GetValeurMatrice(B, j, k);
				SetValeurMatrice(somme, *R, i, j);
			}
		}
		return 0;
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
		return 2;
	}
}

//int ProduitMTMT(Matrice_t, Matrice_t, Matrice_t *);

void ProduitMV(Matrice_t A, Vecteur_t U, Vecteur_t * W) {

	if (U.enColonne == 1 && A.p == U.n){

		(*W).enColonne = 1;
		if ((*W).n != A.n || (*W).V == NULL) {
			int code = RedimensionnerVecteur(W, A.n);
			if (code == 1)
				return;
		}
		
		for (int i=0; i<A.n; i++) {
			double somme = 0;
			for (int k=0; k<U.n; k++)
				somme += GetValeurMatrice(A, i, k) * GetValeurVecteur(U, k);
			SetValeurVecteur(somme, *W, i);
		}
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
	}
}

void ProduitVM(Vecteur_t U, Matrice_t A, Vecteur_t * W) {

	if (U.enColonne == 0 && A.n == U.n){

		(*W).enColonne = 0;
		if ((*W).n != A.p || (*W).V == NULL) {
			int code = RedimensionnerVecteur(W, A.p);
			if (code == 1)
				return;
		}

		for (int i=0; i<A.p; i++) {
			double somme = 0;
			for (int k=0; k<U.n; k++)
				somme += GetValeurMatrice(A, k, i) * GetValeurVecteur(U, k);
			SetValeurVecteur(somme, *W, i);
		}
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
	}
}

void ProduitVV(Vecteur_t U, Vecteur_t V, Matrice_t * R) {

	if (U.enColonne == 1 && V.enColonne == 0) {

		if ((*R).n != U.n || (*R).p != V.n || (*R).M == NULL) {
			int code = RedimensionnerMatrice(R, U.n, V.n);
			if (code == 1)
				return;
		}
		
		for (int i=0; i<U.n; i++) {
			for (int j=0; j<V.n; j++) {
				double produit = GetValeurVecteur(U, i) * GetValeurVecteur(V, j);
				SetValeurMatrice(produit, *R, i, j);
			}
			
		}
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
	}
}



void SommeMM(Matrice_t A, Matrice_t B, Matrice_t * R) {

	if (A.n != B.n || A.p != B.p) {
		
		if ((*R).n != A.n || (*R).p != A.p || (*R).M == NULL) {
			int code = RedimensionnerMatrice(R, A.n, A.p);
			if (code == 1)
				return;
		}

		for (int i=0; i<A.n; i++)
			for (int j=0; j<A.p; j++) {
				double somme = GetValeurMatrice(A, i , j) + GetValeurMatrice(B, i, j);
				SetValeurMatrice(somme, *R, i, j);
			}
	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
	}
}

void SommeVV(Vecteur_t U, Vecteur_t V, Vecteur_t * W) {

	if (U.n == V.n) {

		if ((*W).n != U.n || (*W).V == NULL) {
			int code  = RedimensionnerVecteur(W, U.n);
			if (code == 1)
				return;
		}

		for (int i=0; i<U.n; i++) {
			double somme = GetValeurVecteur(U, i) + GetValeurVecteur(V, i);
			SetValeurVecteur(somme, *W, i);
		}

	} else {
		printf("Multiplication matricielle impossible : dimension incompatible");
	}

}



void Norme1V (Vecteur_t V, double * ps) {
	ps = 0;

	for (int i=0; i<V.n; i++)
		*ps += fabs(GetValeurVecteur(V, i));
}

void Norme2V (Vecteur_t V, double * ps) {
	ps = 0;
	for (int i=0; i<V.n; i++)
		*ps += pow(GetValeurVecteur(V, i), 2);
	*ps = sqrt(*ps);
}

void NormeIV (Vecteur_t V, double * ps) {
	double max = GetValeurVecteur(V, 0);
	for (int i=1; i<V.n; i++)
		if (max < GetValeurVecteur(V, i))
			max = GetValeurVecteur(V, i);
	*ps = max;
}

/*
void Norme1M (Matrice_t, double *);
void Norme2M (Matrice_t, double *);
void NormeIM (Matrice_t, double *);
*/



void TransformerMV(Matrice_t * M, Vecteur_t * V) {
	int taille = (*M).n * (*M).p;
	if ((*V).n != taille || (*V).V == NULL) {
		int code = RedimensionnerVecteur(V, taille);
		if (code == 1)
			return;
	}

	for (int i=0; i<(*M).n; i++)
		for (int j=0; j<(*M).p; j++)
			SetValeurVecteur(GetValeurMatrice(*M, i, j), *V, (*M).n*i + j);
}

void TransformerVM(Matrice_t * M, Vecteur_t * V, int nbLigne, int nbColonne) {
	if ((*V).n == nbLigne*nbColonne) {
		if ((*M).n != nbLigne || (*M).p != nbColonne || (*M).M == NULL) {
			int code = RedimensionnerMatrice(M, nbLigne, nbColonne);
			if (code == 1)
				return;
		}
		for (int i=0; i<(*M).n; i++)
			for (int j=0; j<(*M).p; j++)
				SetValeurMatrice(GetValeurVecteur(*V, i*(*M).n + j), *M, i, j);
				
	} else {
		printf("Transformation du vecteur en matrice impossible");
	}
}



void AppliquerFonctionVecteur(Vecteur_t V, double (*pFonction)(double)) {
	for (int i=0; i<V.n; i++)
		SetValeurVecteur(pFonction(GetValeurVecteur(V, i)), V, i);
}

void AppliquerFonctionMatrice(Matrice_t M, double (*pFonction)(double)) {
	for (int i=0; i<M.n; i++)
		for (int j=0; j<M.p; j++)
			SetValeurMatrice(pFonction(GetValeurMatrice(M, i ,j)), M, i, j);
}



int EgaliteMatrice(Matrice_t A, Matrice_t B) {
	if (A.n != B.n || A.p != B.p)
		return 0;

	int i = 0;
	int j = 0;
	while(GetValeurMatrice(A, i, j) == GetValeurMatrice(B, i, j) && i < A.n) {
		i++;
		j = 0;
		while (GetValeurMatrice(A, i, j) == GetValeurMatrice(B, i, j) && j < A.p)
			j++;
	}

	if (i == A.n && j == A.p)
		return 1;
	else
		return 0;
}

int EgaliteVecteur(Vecteur_t U, Vecteur_t V) {
	if (U.n != V.n)
		return 0;

	int i = 0;
	while (GetValeurVecteur(U, i) == GetValeurVecteur(V, i) && i < U.n)
		i++;
	
	if (i == U.n)
		return 1;
	else
		return 0;
}



void AfficherMatrice(Matrice_t M) {
	for (int i=0; i<M.n; i++) {
		for (int j=0; j<M.p; j++)
			printf("%.2lf ", GetValeurMatrice(M, i, j));
		printf("\n");
	}
	printf("\n");
}

void AfficherVecteur(Vecteur_t V) {
	char apresValeur = V.enColonne == 1 ? '\n' : ' ';
	for (int i=0; i<V.n; i++)
		printf("%.2lf%c", GetValeurVecteur(V, i), apresValeur);
}

void EcrireMatriceFichier(char * nomFichier, Matrice_t M, char * separateur) {
	FILE * file = fopen(nomFichier, "w");
	if (file != NULL) {
		for (int i=0; i<M.n; i++) {
			for (int j=0; j<M.p; j++)
				fprintf(file, "%lf%s", GetValeurMatrice(M, i, j), separateur);
			fprintf(file, "\n");
		}
		fclose(file);
	} else {
		printf("Impossible d'ouvir le fichier \"%s\"\n", nomFichier);
	}
}

void EcrireVecteurFichier(char * nomFichier, Vecteur_t V, char * separateur) {
	FILE * file = fopen(nomFichier, "w");
	if (file != NULL) {
		for (int i=0; i<V.n; i++) {
			fprintf(file, "%lf%s", GetValeurVecteur(V, i), separateur);
		}
		fclose(file);
	} else {
		printf("Impossible d'ouvir le fichier \"%s\"\n", nomFichier);
	}
}



void LibererMatrice(Matrice_t * M) {
	free((*M).M);
	free(M);
	M = NULL;
}

void LibererVecteur(Vecteur_t * V) {
	free((*V).V);
	free(V);
}
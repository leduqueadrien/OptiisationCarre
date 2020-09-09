/* ========================================================================== */
/* 							matrie.h 										  */
/* Contient toutes les fonctions de manipulation des matrices et vexteurs	  */
/* ========================================================================== */

#ifndef MATRICE
#define MATRICE

#include <stdio.h>

/* -------------------------------------------------------------------------- */
/* Matrice : Structure matrice	 											  */
/* int n : nombre de ligne de la matrice                                      */
/* int p : nombre de colonne de la matrice                                    */
/* double * M : tableau contigue de double formant la matrice				  */
/* -------------------------------------------------------------------------- */
typedef struct Matrice {
	int n;
	int p;
	double * M;
} Matrice_t;

/* -------------------------------------------------------------------------- */
/* Matrice : Structure vecteur	 											  */
/* int n : nombre de ligne de la matrice                                      */
/* int enColonne : 1 vecteur colonne, 0 vecteur ligne                         */
/* double * V : tableau contigue de double formant le vecteur				  */
/* -------------------------------------------------------------------------- */
typedef struct Vecteur {
	int n;
	int enColonne;
	double * V;
} Vecteur_t;




/* -------------------------------------------------------------------------- */
/* CreerMatrice : creer la matrice en allouant la mémoire de la structure et  */
/*					du tableau contigue										  */
/* Entree : int n : nombre de ligne de la matrice a creer					  */
/* 			int p : nombre de colonne de la matrice a creer					  */
/* Sortie : Matrice_t * M: pointeur sur la matrice qui vient d'etre cree	  */
/* -------------------------------------------------------------------------- */
Matrice_t * CreerMatrice(int, int);

/* -------------------------------------------------------------------------- */
/* CreerVecteur : creer le vecteur en allouant la mémoire de la structure et  */
/*					du tableau contigue										  */
/* Entree : int n : nombre de ligne du vecteur a creer						  */
/*			int enColonne : 1 vecteur colonne, 0 vecteur ligne				  */
/* Sortie : Vecteur_t * V: pointeur sur le vecteur qui vient d'etre cree	  */
/* -------------------------------------------------------------------------- */
Vecteur_t * CreerVecteur(int, int);



/* -------------------------------------------------------------------------- */
/* RedimensionnerMatrice : Change la taille de la matrice en allouant un	  */
/*							nouveau tableau contigue (aucune copie est faite) */
/* Entree : Matrice_t * M  : pointeur sur la matrice a redimensionner		  */
/*  		int n : nouveau nombre de ligne de la matrice					  */
/*			int p : nouveau nombre de colonne de la matrice					  */
/* Sortie : 0 si le redimensionnement a fonctionner,						  */
/*			1 si l'allocation mémoire ne sait pas faite  					  */
/* -------------------------------------------------------------------------- */
int RedimensionnerMatrice(Matrice_t *, int, int);

/* -------------------------------------------------------------------------- */
/* RedimensionnerVecteur : Change la taille du vecteur en allouant un		  */
/*							nouveau tableau contigue (aucune copie est faite) */
/* Entree : Vecteur_t * V  : pointeur sur le vecteur a redimensionner		  */
/*  		int n : nouveau nombre de ligne du vecteur						  */
/* Sortie : 0 si le redimensionnement a fonctionner,						  */
/*			1 si l'allocation mémoire ne sait pas faite  					  */
/* -------------------------------------------------------------------------- */
int RedimensionnerVecteur(Vecteur_t *, int);



/* -------------------------------------------------------------------------- */
/* GetValeurMatrice : Retourne la valeur d'une case de la matrice			  */
/* Entree : Matrice_t M : matrice dans lequel on veut la valeur				  */
/*			int i : ligne de la case ou l'on veut la valeur					  */
/*			int j : colonne de la case ou l'on veut la valeur				  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
double GetValeurMatrice(Matrice_t, int, int);

/* -------------------------------------------------------------------------- */
/* GetValeurVecteur : Retourne la valeur d'une case du vecteur				  */
/* Entree : Vecteu_t V : vecteur dans lequel on veut la valeur				  */
/*			int i : ligne de la case ou l'on veut la valeur					  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
double GetValeurVecteur(Vecteur_t, int);

/* -------------------------------------------------------------------------- */
/* SetValeurMatrice : Modifie la valeur d'une case de la matrice			  */
/* Entree : double valeur : nouvelle valeur de la case						  */
/*			Matrice_t M : matrice ou on souhaite faire la modification		  */
/*			int n : ligne  de la case a modifier							  */
/*			int p : colonne de la case a modifier							  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void SetValeurMatrice(double, Matrice_t, int, int);

/* -------------------------------------------------------------------------- */
/* SetValeurVecteur : Modifie la valeur d'une case du vecteur				  */
/* Entree : double valeur : nouvelle valeur de la case						  */
/*			Vecteur_t V : vecteur ou on souhaite faire la modification		  */
/*			int n : ligne  de la case a modifier							  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void SetValeurVecteur(double, Vecteur_t, int);


/* -------------------------------------------------------------------------- */
/* RemplirMatriceAleatoire : Remplit la matrice avec des valeurs aleatoires	  */
/* Entree : Matrice_t M : matrice que l'on souhaite remplir					  */
/*			double borneInf : borne inferieur des valeurs aleatoires		  */
/*			double borneSup : borne superieur des valeurs aleatoires		  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void RemplirMatriceAleatoire(Matrice_t, double, double);

/* -------------------------------------------------------------------------- */
/* RemplirVecteurAleatoire : Remplit le vecteur avec des valeurs aleatoires	  */
/* Entree : Vecteur_t V : vecteur que l'on souhaite remplir					  */
/*			double borneInf : borne inferieur des valeurs aleatoires		  */
/*			double borneSup : borne superieur des valeurs aleatoires		  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void RemplirVecteurAleatoire(Vecteur_t, double, double);

/* -------------------------------------------------------------------------- */
/* RemplireMatriceValeur : Remplit la matrice avec une valeur				  */
/* Entree : Matrice_t M : matrice ou l'on souhaite uniformiser les valeurs	  */
/*			double valeur : valeur avec lequelle on souhaite remplir		  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void RemplireMatriceValeur(Matrice_t, double);

/* -------------------------------------------------------------------------- */
/* RemplireVecteurValeur : Remplit le vecteur avec une valeur				  */
/* Entree : Vecteur_t V : vcteur ou l'on souhaite uniformiser les valeurs	  */
/*			double valeur : valeur avec lequelle on souhaite remplir		  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void RemplireVecteurValeur(Vecteur_t, double);


/* -------------------------------------------------------------------------- */
/* TransposerMatrice : Donne la transposee d'une matrice					  */
/*						Le resultat est donnee dans une nouvelle matrice	  */
/* Entree : Matrice_t M : matrice que l'on souhaite transposer				  */
/*			Matrice_t * R : transpose de la matrice							  */
/* Sortie : 0 tout c'est bien passé								  */
/*			1 allocation memoire imposible						  */
/* -------------------------------------------------------------------------- */
int TransposerMatrice(Matrice_t, Matrice_t *);

/* -------------------------------------------------------------------------- */
/* TransposerVecteur : Donne la transposee d'un vecteur						  */
/* Entree : Vecteur_t * V : vecteur que l'on souhaite transposer			  */
/* Sortie : void															  */
/* -------------------------------------------------------------------------- */
void TransposerVecteur(Vecteur_t *);

/* -------------------------------------------------------------------------- */
/* ProduitMM : Multiplication de deux matrices								  */
/* Entree : Matrice_t A : matrice de gauche dans la multiplication			  */
/*			Matrice_t B : matrice de droite dans la multiplication			  */
/*			Matrice_t * R : resultat de la multiplication					  */
/* Sortie : 0 tout c'est bien passe											  */
/*			1 allocation memoire impossible									  */
/*			2 dimension matricielle impossible								  */
/* -------------------------------------------------------------------------- */
int ProduitMM(Matrice_t, Matrice_t, Matrice_t *);

/* -------------------------------------------------------------------------- */
/* ProduitMTM : Multiplication de la transposer de la matrice de gauche		  */
/*				 par une autre												  */
/* Entree : Matrice_t A : matrice de gauche dans la multiplication			  */
/*			Matrice_t B : matrice de droite dans la multiplication			  */
/*			Matrice_t * R : resultat de la multiplication					  */
/* Sortie : 0 tout c'est bien passe											  */
/*			1 allocation memoire impossible									  */
/*			2 dimension matricielle impossible								  */
/* -------------------------------------------------------------------------- */
int ProduitMTM(Matrice_t, Matrice_t, Matrice_t *);

/* -------------------------------------------------------------------------- */
/* ProduitMTM : Multiplication de la transposer de la matrice de droite 	  */
/*				par une autre												  */
/* Entree : Matrice_t A : matrice de gauche dans la multiplication			  */
/*			Matrice_t B : matrice de droite dans la multiplication			  */
/*			Matrice_t * R : resultat de la multiplication					  */
/* Sortie : 0 tout c'est bien passe											  */
/*			1 allocation memoire impossible									  */
/*			2 dimension matricielle impossible								  */
/* -------------------------------------------------------------------------- */
int ProduitMMT(Matrice_t, Matrice_t, Matrice_t *);

/* -------------------------------------------------------------------------- */
/* ProduitMTM : Multiplication de la transposer de la matrice de gauche 	  */
/*				par la transposer de la matrice de droite					  */
/* Entree : Matrice_t A : matrice de gauche dans la multiplication			  */
/*			Matrice_t B : matrice de droite dans la multiplication			  */
/*			Matrice_t * R : resultat de la multiplication					  */
/* Sortie : 0 tout c'est bien passe											  */
/*			1 allocation memoire impossible									  */
/*			2 dimension matricielle impossible								  */
/* -------------------------------------------------------------------------- */
int ProduitMTMT(Matrice_t, Matrice_t, Matrice_t *);

void ProduitMV(Matrice_t, Vecteur_t, Vecteur_t *);
void ProduitMTV(Matrice_t, Vecteur_t, Vecteur_t *);
void ProduitVM(Vecteur_t, Matrice_t, Vecteur_t *);
void ProduitVMT(Vecteur_t, Matrice_t, Vecteur_t *);
void ProduitVTV(Vecteur_t, Vecteur_t, double *);
void ProduitVVT(Vecteur_t, Vecteur_t, Matrice_t *);

void SommeMM(Matrice_t, Matrice_t, Matrice_t *);

void SommeVV(Vecteur_t, Vecteur_t, Vecteur_t *);

void ProduitScalaireEuclidienV(Vecteur_t, Vecteur_t, double *);

void Norme1V(Vecteur_t, double *);
void Norme2V(Vecteur_t, double *);
void NormeIV(Vecteur_t, double *);

void Norme1M(Matrice_t, double *);
void Norme2M(Matrice_t, double *);
void NormeIM(Matrice_t, double *);
void NormeFM(Matrice_t, double *);

void TransformerMV(Matrice_t *, Vecteur_t *);
void TransformerVM(Matrice_t *, Vecteur_t *, int, int);

void AppliquerFonctionVecteur(Vecteur_t, double (*)(double));
void AppliquerFonctionMatrice(Matrice_t, double (*)(double));

int EgaliteMatrice(Matrice_t, Matrice_t);
int EgaliteVecteur(Vecteur_t, Vecteur_t);

void AfficherMatrice(Matrice_t);
void AfficherVecteur(Vecteur_t);

void EcrireMatriceFichier(char *, Matrice_t, char *);
void EcrireVecteurFichier(char *, Vecteur_t, char *);

void LibererMatrice(Matrice_t *);
void LibererVecteur(Vecteur_t *);

#endif


/* Ameliorartion : pour toutes les fonctions de parcour recrouper
 sous une meme fonction les vecteurs et matrices */

/* ATTENTION : prendre en compte les vecteurs et matrices vide (NULL) */
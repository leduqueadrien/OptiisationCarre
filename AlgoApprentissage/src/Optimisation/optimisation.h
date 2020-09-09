

#ifndef OPTIMISATION
#define OPTIMISATION

typedef struct Fonction
{
	int nbCase;			/* Entree */
	double longueur;	/* Entree */
	double hauteur;		/* Entree */
	double tailleCase;	/* Sortie */
	int borneInfNbCase;		/* Parametre */
	int borneSupNbCase;		/* Parametre */
	double borneInfFenetre;	/* Parametre */
	double borneSupFenetre;	/* Parametre */
} Fonction_t;


Fonction_t * CreerFonction();
void ParametrerFonctionFichier(char *, Fonction_t *);
void InitialisationFonction(Fonction_t *, int, int, double, double);
void GenererEntreeFoncton(Fonction_t *);
void ResoudreFonction(Fonction_t *);
double ResoudreOptimisationCarre(double, double, int);

Fonction_t ** CreerTabFonction(int);
void RemplirTabFonctoion(Fonction_t **, int, int, double, double);

void AfficherFoncrion(Fonction_t *);

void LibererFonction(Fonction_t *);

#endif
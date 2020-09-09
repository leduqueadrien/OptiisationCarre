
#ifndef NETWORKH
#define NETWORKH


#include"../Matrice/matrice.h"

/* Convention : W*X+B */

typedef struct Couche
{
    int tailleEntree;
    int tailleSortie;
    Matrice_t * W;
    Vecteur_t * vectEntree;
    Vecteur_t * vectSortie;
    double (*pActivation)(double, int);
} Couche_t;

typedef struct Network
{
    int tailleEntree;
    int tailleSortie;
    int nbCoucheCachee;
    Couche_t ** tabCouche;
} Network_t;

Network_t NETWORK;



int InitialiserNetwork();       // Depuis la lecture d'un fichier de configuration et depuis un network enregistrer
Couche_t * CreerCouche();
void InitialiserNetworkAlea(double, double);

void AfficherCouche(Couche_t *);
void AfficherNetwork();

void Apprentissage();       // A faire
void RetropropagationGradient();        //A faire


void LibererCouche(Couche_t *);
void LibererNetwork();

void EnregistrerNetwork();      // A faire

double sigmoide(double, int);
double identite(double, int);
double quadratique(double, int);


#endif
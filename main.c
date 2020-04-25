
#include<stdio.h>
#include<math.h>

void Optimisation (int, int, int, double, int *, int *, double *);

int main() {
    int hauteur;
    int largeur;
    int nbElemet;
    double pourcentageRemplissage;

    int nbColonne;
    int nbLigne;
    double tailleCarre;

    printf("Hauteur de la fenetre : ");
    scanf("%d", &hauteur);
    printf("Largeur de la fenetre : ");
    scanf("%d", &largeur);
    printf("Nombre d'element a rentrer : ");
    scanf("%d", &nbElemet);
    printf("Pourcentage de remplissage [1,0] : ");
    scanf("%lf", &pourcentageRemplissage);

    printf("\n");
    Optimisation(hauteur, largeur, nbElemet, pourcentageRemplissage, &nbLigne, &nbColonne, &tailleCarre);
    printf("\n");

    printf("nombre ligne : %d\nnombre de colonne : %d\ntaille du carre : %lf\n",nbLigne, nbColonne, tailleCarre);

    return 0;
}

void Optimisation (int hauteur, int largeur, int nbElem, double pourcRemplissage, int * nbLigne, int * nbColonne, double * tailleCarre) {
    // 2 equations :
    // x*nbColonne <= pourcRemplissage*largeur
    // x*nbLigne <= pourcRemplissage*hauteur

    // Je cherche le nombre de colonne au point de croisement des 2 droites d'equation ci-dessus
    *nbColonne = sqrt(nbElem*largeur/hauteur);

    // Comme le nombre de colonne doit etre entier et non reel,
    // je regarde quelle partie entiere inferieure ou superieure est la moins contraignante vis à vis de la taille du carre
    double tailleCarreInf = pourcRemplissage*largeur/(*nbColonne+1);
    double tailleCarreSup = pourcRemplissage*hauteur*(*nbColonne)/nbElem;
    
    if (tailleCarreSup > tailleCarreInf) {
        *tailleCarre = tailleCarreSup;
    } else {
        *tailleCarre = tailleCarreInf;
        *nbColonne += 1;
    }

    // A partir du nombre de colonne, j'en deduit le nombre de ligne
    *nbLigne = nbElem/(*nbColonne);
    if (nbElem%(*nbColonne) != 0)
        *nbLigne += 1;
}
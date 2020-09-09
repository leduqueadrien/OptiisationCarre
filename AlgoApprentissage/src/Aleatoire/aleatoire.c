
#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>

void SetUpSeed() {
	srand(time(NULL));
}

double GenererDoubleAleatoire(double borneInf, double borneSup) {
	static int cpt = 0;
	cpt++;
	srand(cpt*time(NULL));
	return rand()/(double)RAND_MAX*(borneSup-borneInf) + borneInf;
}

int GenererIntAleatoire(int borneInf, int borneSup) {
	static int cpt = 0;
	cpt++;
	srand(cpt*time(NULL));
	return rand()/(int)RAND_MAX*(borneSup-borneInf) + borneInf;
}

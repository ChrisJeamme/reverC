#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"


int main()
{
	affiche_legende_couleurs();
	matrice M=init_matrice();
	affiche_matrice(M);
	return 0;
}
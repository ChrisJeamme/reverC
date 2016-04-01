#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

#define BLANC 7
#define NOIR 0

void couleur_fond(int couleur) 
{
	printf("\033[4%dm", couleur);
}

void reset_couleurs() 
{
	printf("\033[0m");
}


void affiche_legende_couleurs() 
{
	/* affiche la legende des couleurs*/
	printf("Legende :\n");
	printf(" Pions de l'ordinateur : "); 
	couleur_fond(NOIR); 
	printf("  ");
	reset_couleurs();
	printf("\n"); 
	printf(" Pions du joueur : "); 
	couleur_fond(BLANC); 
	printf("  ");
	reset_couleurs();
	printf("\n");
}


int main()
{
	affiche_legende_couleurs();
	return 0;
}

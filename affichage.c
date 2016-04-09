#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

#define BLANC 7
#define NOIR 4
#define TAILLE 8

void couleur_fond(int couleur) 
{
	printf("\033[4%dm", couleur);
}

void reset_couleurs() 
{
	printf("\033[0m");
}

void coloration(int couleur)
{
	couleur_fond(couleur);
	printf("  ");
	reset_couleurs();
}

void affiche_legende_couleurs() 
{
	/* affiche la legende des couleurs*/
	printf("Legende :\n");
	printf(" Pions de l'ordinateur : "); 
	coloration(NOIR);
	printf("\n"); 
	printf(" Pions du joueur : "); 
	coloration(BLANC);
	printf("\n");
}


void affiche_matrice(matrice M)
{
	int i, j;
	printf("    A B C D E F G H\n");
	printf("   _________________\n");
	for (i=0; i<TAILLE; i++)
	{
		printf("%d | ", i+1);
		for (j=0; j<TAILLE; j++)
		{
			if (M[i][j].couleur=='V')
			{
				printf(". ");
			}
			if (M[i][j].couleur=='B')
			{
				coloration(BLANC);
			}
			if (M[i][j].couleur=='N')
			{
				coloration(NOIR);
			}
		}
		printf("|\n");
	}
	printf("  |_________________|\n");
}
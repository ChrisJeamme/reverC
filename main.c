#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "fonctions_jeu.h"


int main()
{
	matrice M=init_matrice();
	char coup[2];
	int i, j;
	int joueur=1;
	char nom[50];
	char *ordi="l\'ordinateur";
	printf("Quel est votre nom ?\n");
	fscanf(stdin, "%s", nom);

	affiche_legende_couleurs();

	while ( peut_jouer(M, 1) || peut_jouer(M, 2))
	{
		affiche_matrice(M);
		if (!peut_jouer(M, joueur))
		{
			printf("%s ne peut pas jouer", (joueur==1)?nom:ordi);
			joueur=changer_joueur(joueur);
		}
		else
		{
			printf("Au tour de %s : \n", (joueur==1)?nom:ordi);
			do
			{	
				printf("Rentrer un coup :\n");
				fscanf(stdin, "%s", coup);
				if (verif_coup(coup))
				{
					if (verif_coup(coup) == 1)
					{
						i=convertir(coup[0]);
						j=convertir(coup[1]);
					}
					else
					{
						j=convertir(coup[0]);
						i=convertir(coup[1]);
					}
				}
				
			} while (!coup_valide(M, i, j, joueur));
			M=changer(M, i, j, joueur);
			joueur=changer_joueur(joueur);
		}

	}
	affiche_matrice(M);
	printf("La partie est terminée\n");
	return 0;
}
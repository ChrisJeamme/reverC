#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "fonctions_jeu.h"


int main()
{
	int joueur, affiche_menu=1, numMod=0;
	char nom[50], choixMod[1];

	while (affiche_menu==1)
	{
		clear();
		printf(	"\n  888888ba                                        a88888b.\n"
				"  88    `8b                                      d8'   `88\n"
				"  88aaaa8P' .d8888b. dP   .dP .d8888b. 88d888b.  88        \n"
				"  88   `8b. 88ooood8 88   d8' 88ooood8 88'  `88  88        \n"
				"  88     88 88.  ... 88 .88'  88.  ... 88        Y8.   .88 \n"
				"  dP     dP `88888P' 8888P'   `88888P' dP         Y88888P' \n\n");
	
		printf("____________________________________________________________\n\n\n");
		affiche_menu=0;

		while( (numMod < 1) || (numMod > 2) )
		{
			fprintf(stdout," Entrez le numero correspondant a votre choix:\n\n"
							"\t(1) Nouvelle partie\n"
							"\t(2) Quitter le jeu\n");
			fscanf(stdin,"%s",choixMod); /*On se sert d'une chaine de caractère pour éviter des problème de boucle infini si on rentre autre chose qu'un int*/
			numMod=atoi(choixMod); /*On convertit en entier*/
			if( (numMod < 1) || (numMod > 5) ) /*Boucle si réponse incorrecte*/
			{
				fprintf(stdout,"\nChoix incorrect, veuillez recommencer:\n\n");
			}
		}
		clear();

	

		if (numMod==1)
		{
			printf("Quel est votre nom ?\n");
			fscanf(stdin, "%s", nom);

			matrice M=init_matrice();

			affiche_legende_couleurs(nom);

			joueur=1;


			/* JEU */
			partie(M, nom, joueur);


			affiche_matrice(M);
			printf("La partie est terminée\n");
			affiche_gagnant(M);
			printf("\nAppuyer sur entrée pour revenir au menu principal\n");
			purger();
			getchar();
			affiche_menu=1;
			numMod=0;
		}

		
		if (numMod==2)
		{
			printf("A bientôt !\n");
		}

	}
	return 0;
}
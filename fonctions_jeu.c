#include <string.h>
#include <stdio.h>
#include "fonctions_jeu.h"
#include "affichage.h"


int verif_coup(char *coup)
{
	if (strlen(coup)!=2)
	{
		return 0;	
	}
	if (coup[0]>'0' && coup[0]<'9')
	{
		if ((coup[1]>='A' && coup[1]<'I') || (coup[1]>='a' && coup[1]<'i'))
		{
			return 1;
		}
	}
	if ((coup[0]>='A' && coup[0]<'I') || (coup[0]>='a' && coup[0]<'i'))
	{
		if (coup[1]>'0' && coup[1]<'9')
		{
			return 2;
		}
	}
	return 0;
}

int convertir (char c)
{
	if (c>'0' && c<'9') /*si c'est un chiffre*/
	{
		return c-'1'; /*car 1A correspond à M[0][0]*/
	}
	else if (c>='A' && c<'I')
	{
		return c-'A';
	}
	else return c-'a';
}

int coup_valide (matrice M, int i, int j, int joueur)
{
	char pion_joueur, pion_adv;
	if (joueur == 1) /*Le joueur 1 est le joueur*/
	{
		pion_joueur='B';
		pion_adv='N';
	}
	else
	{
		pion_joueur='N';
		pion_adv='B';
	}

	int x, y, k;

	if (M[i][j].couleur != 'V')
	{
		return 0;
	}

	/*On regarde si c'est valide en haut à gauche*/
	x=i;
	y=j;
	k=0;
	while (M[x][y].hg!=NULL && M[x][y].hg->couleur == pion_adv)
	{
		x--;
		y--;
		k++;
	}
	if (k!=0 && M[x][y].hg!=NULL && M[x][y].hg->couleur == pion_joueur)
	{
		return 1;
	}


	/*En haut*/
	x=i;
	y=j;
	k=0;
	while(M[x][y].h!=NULL && M[x][y].h->couleur == pion_adv)
	{
		x--;
		k++;
	}
	if (k!=0 && M[x][y].h!=NULL && M[x][y].h->couleur == pion_joueur)
	{
		return 1;
	}

	/* En haut à droite */
	x=i;
	y=j;
	k=0;
	while(M[x][y].hd!=NULL && M[x][y].hd->couleur == pion_adv)
	{
		x--;
		y++;
		k++;
	}
	if (k!=0 && M[x][y].hd!=NULL && M[x][y].hd->couleur == pion_joueur)
	{
		return 1;
	}

	/* A gauche */
	x=i;
	y=j;
	k=0;
	while(M[x][y].g!=NULL && M[x][y].g->couleur == pion_adv)
	{
		y--;
		k++;
	}
	if (k!=0 && M[x][y].g!=NULL && M[x][y].g->couleur == pion_joueur)
	{
		return 1;
	}

	/* A droite */
	x=i;
	y=j;
	k=0;
	while(M[x][y].d!=NULL && M[x][y].d->couleur == pion_adv)
	{
		y++;
		k++;
	}
	if (k!=0 && M[x][y].d!=NULL && M[x][y].d->couleur == pion_joueur)
	{
		return 1;
	}

	/* En bas à gauche */
	x=i;
	y=j;
	k=0;
	while(M[x][y].bg!=NULL && M[x][y].bg->couleur == pion_adv)
	{
		x++;
		y--;
		k++;
	}
	if (k!=0 && M[x][y].bg!=NULL && M[x][y].bg->couleur == pion_joueur)
	{
		return 1;
	}

	/* En bas */
	x=i;
	y=j;
	k=0;
	while(M[x][y].b!=NULL && M[x][y].b->couleur == pion_adv)
	{
		x++;
		k++;
	}
	if (k!=0 && M[x][y].b!=NULL && M[x][y].b->couleur == pion_joueur)
	{
		return 1;
	}

	/* En bas à droite */
	x=i;
	y=j;
	k=0;
	while(M[x][y].bd!=NULL && M[x][y].bd->couleur == pion_adv)
	{
		x++;
		y++;
		k++;
	}
	if (k!=0 && M[x][y].bd!=NULL && M[x][y].bd->couleur == pion_joueur)
	{
		return 1;
	}
	return 0;
}


matrice changer (matrice M, int i, int j, int joueur)
{
	char pion_joueur, pion_adv;
	if (joueur == 1) /* Le joueur 1 est le joueur */
	{
		pion_joueur='B';
		pion_adv='N';
	}
	else
	{
		pion_joueur='N';
		pion_adv='B';
	}

	int changements[8]={0};
	int x, y;

	M[i][j].couleur=pion_joueur;

	x=i;
	y=j;
	while (M[x][y].hg!=NULL && M[x][y].hg->couleur == pion_adv)
	{	
		changements[0]++;
		x--;
		y--;
	}
	if (M[x][y].hg==NULL || M[x][y].hg->couleur != pion_joueur)
	{
		changements[0] = 0;
	}


	/*En haut */
	x=i;
	y=j;
	while(M[x][y].h!=NULL && M[x][y].h->couleur == pion_adv)
	{
		changements[1]++;
		x--;
	}
	if (M[x][y].h==NULL || M[x][y].h->couleur != pion_joueur)
	{
		changements[1] = 0;
	}

	/* En haut à droite */
	x=i;
	y=j;
	while(M[x][y].hd!=NULL && M[x][y].hd->couleur == pion_adv)
	{
		changements[2]++;
		x--;
		y++;
	}
	if (M[x][y].hd==NULL || M[x][y].hd->couleur != pion_joueur)
	{
		changements[2] = 0;
	}

	/* A gauche */
	x=i;
	y=j;
	while(M[x][y].g!=NULL && M[x][y].g->couleur == pion_adv)
	{
		changements[3]++;
		y--;
	}
	if (M[x][y].g==NULL || M[x][y].g->couleur != pion_joueur)
	{
		changements[3] = 0;
	}

	/* A droite */
	x=i;
	y=j;
	while(M[x][y].d!=NULL && M[x][y].d->couleur == pion_adv)
	{
		changements[4]++;
		y++;
	}
	if (M[x][y].d==NULL || M[x][y].d->couleur != pion_joueur)
	{
		changements[4] = 0;
	}

	/* En bas à gauche */
	x=i;
	y=j;
	while(M[x][y].bg!=NULL && M[x][y].bg->couleur == pion_adv)
	{
		changements[5]++;
		x++;
		y--;
	}
	if (M[x][y].bg==NULL || M[x][y].bg->couleur != pion_joueur)
	{
		changements[5] = 0;
	}

	/* En bas */
	x=i;
	y=j;
	while(M[x][y].b!=NULL && M[x][y].b->couleur == pion_adv)
	{
		changements[6]++;
		x++;
	}
	if (M[x][y].b==NULL || M[x][y].b->couleur != pion_joueur)
	{
		changements[6] = 0;
	}
	/* En bas à droite */
	x=i;
	y=j;
	while(M[x][y].bd!=NULL && M[x][y].bd->couleur == pion_adv)
	{
		changements[7]++;
		x++;
		y++;
	}
	if (M[x][y].bd==NULL || M[x][y].bd->couleur != pion_joueur)
	{
		changements[7] = 0;
	}

	x=i; 
	y=j;
	while(changements[0]!=0)
	{
		M[x][y].hg->couleur=pion_joueur;
		x--;
		y--;
		changements[0]--;
	}

	x=i; 
	y=j;
	while(changements[1]!=0)
	{
		M[x][y].h->couleur=pion_joueur;
		x--;
		changements[1]--;
	}

	x=i; 
	y=j;
	while(changements[2]!=0)
	{
		M[x][y].hd->couleur=pion_joueur;
		x--;
		y++;
		changements[2]--;
	}

	x=i; 
	y=j;
	while(changements[3]!=0)
	{
		M[x][y].g->couleur=pion_joueur;
		y--;
		changements[3]--;
	}

	x=i; 
	y=j;
	while(changements[4]!=0)
	{
		M[x][y].d->couleur=pion_joueur;
		y++;
		changements[4]--;
	}

	x=i; 
	y=j;
	while(changements[5]!=0)
	{
		M[x][y].bg->couleur=pion_joueur;
		x++;
		y--;
		changements[5]--;
	}

	x=i; 
	y=j;
	while(changements[6]!=0)
	{
		M[x][y].b->couleur=pion_joueur;
		x++;
		changements[6]--;
	}

	x=i; 
	y=j;
	while(changements[7]!=0)
	{
		M[x][y].bd->couleur=pion_joueur;
		x++;
		y++;
		changements[7]--;
	}
	return M;
}


/* Fonction qui retourne 1 s'il existe au moins un coup valide pour un joueur, 0 sinon */
int peut_jouer(matrice M, int joueur)
{
	int i, j;
	int nb_coups_jouables=0;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			nb_coups_jouables+=coup_valide(M, i, j, joueur);
		}
	}
	if (nb_coups_jouables == 0)
	{
		return 0;
	}
	else return 1;
}

/* Fonction pour changer de joueur */
int changer_joueur(joueur)
{
	if (joueur==1)
		return 2;
	else return 1;
}

int calcul_gagnant(matrice M)
{
	int i, j, j1=0, j2=0;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			if (M[i][j].couleur == 'B')
				j1++;
			if (M[i][j].couleur == 'N')
				j2++;
		}
	}

	if (j1 > j2)
		return 1;
	if (j1 < j2)
		return 2;
	return 3;
}

void affiche_gagnant(matrice M)
{
	int gagnant=calcul_gagnant(M);

	if (gagnant==1)
	{
		printf("Félicitations ! Vous avez gagné contre l'ordinateur\n");
	}
	if (gagnant==2)
	{
		printf("L'ordinateur a remporté la partie.\n");
	}
	if (gagnant==3)
	{
		printf("Egalité !\n");
	}
}

matrice partie(matrice M, char *nom, int joueur)
{
	char coup[2];
	char *ordi="l\'ordinateur";
	int i, j;

	while ( peut_jouer(M, 1) || peut_jouer(M, 2))
	{
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
				affiche_matrice(M);
				printf("Rentrez un coup :\n");
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
			purger();
			clear();
		}

	}
	return M;
}
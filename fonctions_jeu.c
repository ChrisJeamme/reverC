#include <string.h>
#include <stdio.h>
#include "fonctions_jeu.h"


int verif_coup(char *coup)
{
	if (strlen(coup)!=2 || coup[0]<'1' || coup[0]>'8' || coup[1]<'A' || coup[1]>'H')
	{
		return 0;	
	}
	else return 1;
}

int convertir (char c)
{
	if (c>'0' && c<'9') //si c'est un chiffre
	{
		return c-'1'; //car 1A correspond à M[0][0]
	}
	else 
	{
		return c-'A';
	}
}

int coup_valide (matrice M, int i, int j, int joueur)
{
	char pion_joueur, pion_adv;
	if (joueur == 1) //Le joueur 1 est le joueur
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

	//On regarde si c'est valide en haut à gauche
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


	//En haut
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

	// En haut à droite
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

	// A gauche
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

	// A droite
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

	// En bas à gauche
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

	// En bas
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

	// En bas à droite
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
	if (joueur == 1) //Le joueur 1 est le joueur
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


	//En haut
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

	// En haut à droite
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

	// A gauche
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

	// A droite
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

	// En bas à gauche
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

	// En bas
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
	// En bas à droite
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


// Fonction qui retourne 1 s'il existe au moins un coup valide pour un joueur, 0 sinon
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

// Fonction pour changer de joueur
int changer_joueur(joueur)
{
	if (joueur==1)
		return 2;
	else return 1;
}
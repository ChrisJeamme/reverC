#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#define TAILLE 8

matrice creer_matrice()
{
	return NULL;
}

matrice init_matrice()
{
	int i,j;
	matrice M=creer_matrice();
	M=(matrice)malloc(TAILLE*sizeof(cellule*));
	for (i = 0; i< TAILLE; i++)
	{
		M[i]=(cellule*)malloc(TAILLE*sizeof(cellule));
	}

	for (i=0; i<TAILLE; i++)
	{
		for (j=0; j<TAILLE; j++)
		{

			if (i==0)
			{
				M[i][j].hg=NULL;
				M[i][j].h=NULL;
				M[i][j].hd=NULL;
				if (j==0 || j==TAILLE-1)
				{
					if (j==0)
					{
						M[i][j].g=NULL;
						M[i][j].bg=NULL;
						M[i][j].b=&M[i+1][j];
						M[i][j].bd=&M[i+1][j+1];
						M[i][j].d=&M[i][j+1];
					}
					if (j==TAILLE-1)
					{
						M[i][j].d=NULL;
						M[i][j].bd=NULL;
						M[i][j].b=&M[i+1][j];
						M[i][j].bg=&M[i+1][j-1];
						M[i][j].g=&M[i][j-1];
					}
				}
				else 
				{
					M[i][j].d=&M[i][j+1];
					M[i][j].g=&M[i][j-1];
					M[i][j].bd=&M[i+1][j+1];
					M[i][j].b=&M[i+1][j];
					M[i][j].bg=&M[i+1][j-1];
				}
			}

			else if (i==TAILLE-1)
			{
				M[i][j].bg=NULL;
				M[i][j].b=NULL;
				M[i][j].bd=NULL;
				if (j==0 || j==TAILLE-1)
				{
					if (j==0)
					{
						M[i][j].g=NULL;
						M[i][j].hg=NULL;
						M[i][j].h=&M[i-1][j];
						M[i][j].hd=&M[i-1][j+1];
						M[i][j].d=&M[i][j+1];
					}
					if (j==TAILLE-1)
					{
						M[i][j].d=NULL;
						M[i][j].hd=NULL;
						M[i][j].h=&M[i-1][j];
						M[i][j].hg=&M[i-1][j-1];
						M[i][j].g=&M[i][j-1];
					}
				}
				else 
				{
					M[i][j].d=&M[i][j+1];
					M[i][j].g=&M[i][j-1];
					M[i][j].hd=&M[i-1][j+1];
					M[i][j].h=&M[i-1][j];
					M[i][j].hg=&M[i-1][j-1];
				}
			}
			else if (j==0)
			{
				M[i][j].hg=NULL;
				M[i][j].g=NULL;
				M[i][j].bg=NULL;
				M[i][j].h=&M[i-1][j];
				M[i][j].b=&M[i+1][j];
				M[i][j].hd=&M[i-1][j+1];
				M[i][j].d=&M[i][j+1];
				M[i][j].bd=&M[i+1][j+1];
			}
			else if (j==TAILLE-1)
			{
				M[i][j].hd=NULL;
				M[i][j].d=NULL;
				M[i][j].bd=NULL;
				M[i][j].hg=&M[i-1][j-1];
				M[i][j].g=&M[i][j-1];
				M[i][j].bg=&M[i+1][j-1];
				M[i][j].h=&M[i-1][j];
				M[i][j].b=&M[i+1][j];
			}
			else
			{
				M[i][j].hg=&M[i-1][j-1];
				M[i][j].h=&M[i-1][j];
				M[i][j].hd=&M[i-1][j+1];
				M[i][j].g=&M[i][j-1];
				M[i][j].d=&M[i][j+1];
				M[i][j].bg=&M[i+1][j-1];
				M[i][j].b=&M[i+1][j];
				M[i][j].bd=&M[i+1][j+1];
			}

			if ((i==3 || i==4) && (j==3 || j==4))
			{
				if (i==j)
					M[i][j].couleur='B';
				else
					M[i][j].couleur='N';
			}
			else
			{
				M[i][j].couleur='V';
			}
		}
	}
	return M;
}

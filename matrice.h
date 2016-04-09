typedef struct cellule
{
	char couleur;
	struct cellule *hg;
	struct cellule *h;
	struct cellule *hd;
	struct cellule *g;
	struct cellule *d;
	struct cellule *bg;
	struct cellule *b;
	struct cellule *bd;
}cellule;

typedef cellule ** matrice;


matrice creer_matrice();
matrice init_matrice();

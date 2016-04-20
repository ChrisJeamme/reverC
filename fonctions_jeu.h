#include "matrice.h"

int verif_coup(char *coup);

int convertir (char c);

int coup_valide (matrice M, int i, int j, int joueur);

int peut_jouer(matrice M, int joueur);

int changer_joueur(int joueur);

matrice changer (matrice M, int i, int j, int joueur);

int calcul_gagnant(matrice M);

void affiche_gagnant(matrice M);

matrice partie(matrice M, char *nom, int joueur);
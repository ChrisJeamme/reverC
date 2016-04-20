CC=gcc
OPTIONS=-Wall -ansi

reverC: matrice.o affichage.o fonctions_jeu.o main.o
	$(CC) $(OPTIONS) matrice.o affichage.o main.o fonctions_jeu.o -o reverC

matrice.o: matrice.c matrice.h
	$(CC) $(OPTIONS) -c matrice.c -o matrice.o

affichage.o: affichage.c affichage.h
	$(CC) $(OPTIONS) -c affichage.c -o affichage.o

fonctions_jeu.o: fonctions_jeu.c fonctions_jeu.h
	$(CC) $(OPTIONS) -c fonctions_jeu.c -o fonctions_jeu.o

main.o: main.c
	$(CC) $(OPTIONS) -c main.c -o main.o

clean:
	rm -f *.o
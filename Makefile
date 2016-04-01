CC=gcc
OPTIONS=-Wall

reverC: matrice.o affichage.o main.o
	$(CC) $(OPTIONS) matrice.o affichage.o main.o -o reverC

matrice.o: matrice.c matrice.h
	$(CC) $(OPTIONS) -c matrice.c -o matrice.o

affichage.o: affichage.c affichage.h
	$(CC) $(OPTIONS) -c affichage.c -o affichage.o

main.o: main.c
	$(CC) $(OPTIONS) -c main.c -o main.o

clean:
	rm -f *.o
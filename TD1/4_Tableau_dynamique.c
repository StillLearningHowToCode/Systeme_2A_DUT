#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

// Main
int main(int argc, char *argv[])
{
    int taille = 0;
    printf("Saisir la taille du tableau :");
    scanf("%d", &taille); //taille est définie ici, pas besoin de la réattribuer
    printf("Taille du tableau : %d\n", taille);

    int tab[taille]; // tableau d'entier car int
    for (int i = 0; i < taille; i++)
    {
        printf("%d", tab[i]);
        printf("\n");
    }

    /* Initialise le générateur aléatoires
    srand (time(NULL));
    printf ("First number: %d\n", rand()%100);
    printf ("First number: %d\n", rand()%100);
    printf ("First number: %d\n", rand()%100);*/
    return 0;
}
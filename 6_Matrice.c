#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
// Variables
#define NB_MIN 0
#define NB_MAX 100
#define MIN_LIGNE 2
#define MAX_LIGNE 10

// Entêtes
int randomNumber();

int main(int argc, char *argv[])
{
    /* Déclarations */
    int *matrice;
    int U[50][50];            /* matrice unitaire */
    int colonne, ligne, i, j; /* dimension de la matrice unitaire */
    /*int I, J;       indices courants */

    /* Saisie des données */
    printf("Dimension de la matrice (max.50) : \n");
    printf("Veuillez entrer le nombre de colonnes : ");
    scanf("%d", &colonne);
    printf("Veuillez entrer le nombre de lignes : ");
    scanf("%d", &ligne);

    matrice = malloc(ligne * colonne * sizeof(int));

    /* Si la matrice est remplie à la main
    for (i = 0; i < ligne; i++)
    {
        printf("Quelles sont les coefficients de la colonne %d ?\n", i);
        for (j = 0; j < colonne; j++)
        {
            printf("coefficients %d ? \n", j);
            scanf("%d", &(matrice[i * colonne + j]));
        }
    }*/

    //Remplissage "random"
    srand(time(NULL));
    for (i = 0; i < ligne; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            int random = randomNumber();
            printf("%d", random);
        }
    }

    printf("\nVotre matrice est : \n");
    for (i = 0; i < ligne; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d  ", matrice[i * colonne + j]);
        }
        printf("\n");
    }
    return 0;
}

int randomNumber() {
    return (rand() % (NB_MAX - NB_MIN)) + NB_MIN;
}
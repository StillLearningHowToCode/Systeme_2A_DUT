#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

// Entêtes
// int demandeSaisie();
// int afficher(int taille);

// Main
int main(int argc, char *argv[])
{
    // Variables
    int taille = 20;
    char rep;

    printf("Saisir la taille du tableau :");
    scanf("%d", &taille); //taille est définie ici, pas besoin de la réattribuer
    printf("Taille du tableau : %d\n", taille);
    // Affichage
    printf("Affichage du tableau :\n");
    int tab[taille]; // tableau d'entier car int
    for (int i = 0; i < taille; i++)
    {
        printf("%d", tab[i]);
        printf("\n");
    }
    printf("Voulez vous redimmensionner le tableau ? o/n\n");
    scanf("%s", &rep);
    getchar();
    if ((strcmp(&rep, "o") ==0))
    //(strcmp(rep, ('o' || 'O'))==0)
    {
        printf("Let's gooooo !\n");
        printf("Saisir la taille du tableau :");
        scanf("%d", &taille); //taille est définie ici, pas besoin de la réattribuer
        printf("Taille du tableau : %d\n", taille);
    }
    else
    {
        printf("Fin du programme");
    }
    return 0;
}

// int afficher(int taille)
// {
//     //int taille = 0;
//     printf("Affichage du tableau :\n");
//     int tab[taille]; // tableau d'entier car int
//     for (int i = 0; i < taille; i++)
//     {
//         printf("%d", tab[i]);
//         printf("\n");
//     }
//     return taille;
// }

// int demandeSaisie(int taille)
// {
//     printf("Saisir la taille du tableau :");
//     scanf("%d", &taille); //taille est définie ici, pas besoin de la réattribuer
//     printf("Taille du tableau : %d\n", taille);
//     return taille;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

// Entêtes
void demandeSaisie(taille);
void afficher(taille);

// Main
int main(int argc, char *argv[])
{
    // Variables
    int taille = 0;
    char rep;

    demandeSaisie(taille);
    afficher(taille);
    printf("Voulez vous redimmensionner le tableau ? o/n");
    scanf("%s", &rep);
    if (rep == ('o' || 'O'))
    {
        printf("Let's gooooo \n");
        demandeSaisie(taille);
        afficher(taille);
    }
    else
    {
        printf("See you later then!");
    }
    demandeSaisie(taille);
    afficher(taille);
    return 0;
}

void afficher(taille)
{
    printf("Affichage du tableau :\n");
    int tab[taille]; // tableau d'entier car int
    for (int i = 0; i < taille; i++)
    {
        printf("%d", tab[i]);
        printf("\n");
    }
}

void demandeSaisie(taille)
{
    printf("Saisir la taille du tableau :");
    scanf("%d", &taille); //taille est définie ici, pas besoin de la réattribuer
    printf("Taille du tableau : %d\n", taille);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char nom[50];
    char prenom[50];
    int res;
    printf("Saisissez votre nom suivi de votre prénom : ");
    res = scanf("%49s%49s", nom, prenom);
    if (res == 2)
        printf("Vous vous appelez %s %s, est-ce correct ?\n", prenom, nom);
    else
        printf("Vous avez fait une erreur lors de la saisie.\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int main()
{
    // Variables
    int i;
    char chaine;

    // Message de demande de saisie
    printf("Veuillez entrer une chaine de caracteres ou une phrase : ");

    // Allocation des espaces mémoire nécessaires sur le tas :
    // Allocation de 3 pointeurs
    char **tab_chaine = (char **)malloc(3 * sizeof(char *));
    for (i = 0; i < 3; i++)
        // Allocation pour 100 caractères + 1 caractère nul final
        tab_chaine[i] = (char *)malloc(101);

    // Saisie des chaînes de caractères :
    for (i = 0; i < 3; i++)
        // Saisie d'une  chaîne de 10 caractères maximum
        scanf("%100s", tab_chaine[i]);

    // Affichage des chaînes de caractères :
    for (i = 0; i < 3; i++)
        printf("%s\n", tab_chaine[i]);

    // Libération des espaces alloués :
    for (i = 0; i < 3; i++)
        free(tab_chaine[i]);
    free(tab_chaine);

    return 0;
}
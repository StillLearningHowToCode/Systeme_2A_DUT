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
    char str[100];
    int x, count = 1;

    /*Message de demande de saisie
    printf("Veuillez entrer une chaine de caracteres ou une phrase : \n");
    gets(str);

    for (x = 0; str[x] != '\0'; x++)
    {
        if (str[x] == ' ' || str[x] == '\t' || str[x] == '\n')
        {
            count++;
        }
    }
    printf("Le nombre total de mots dans cette chaine est = %d", count);*/

    // Allocation des espaces mémoire nécessaires sur le tas :
    // Allocation de 3 pointeurs
    char **tab_chaine = (char **)malloc(3 * sizeof(char *));
    for (i = 0; i < count; i++)
        // Allocation pour 100 caractères + 1 caractère nul final
        tab_chaine[i] = (char *)malloc(101);

    // Saisie des chaînes de caractères :
    // for (i = 0; i < count; i++)
    //     // Saisie d'une  chaîne de 100 caractères maximum
    //     scanf("%100s", tab_chaine[i]);

    // test saisie
    printf("Veuillez entrer une chaine de caracteres ou une phrase : \n");
    //on compte le nb de mots but wut
    gets(str);

    for (x = 0; str[x] != '\0'; x++)
    {
        if (str[x] == ' ' || str[x] == '\t' || str[x] == '\n')
        {
            count++;
        }
    }
    for (i = 0; i < count; i++)
        // Saisie d'une  chaîne de 100 caractères maximum
        scanf("%100s", tab_chaine[i]);
        
    printf("\nLe nombre total de mots dans cette chaine est = %d", count);
    // fin test saisie

    // Affichage des chaînes de caractères :
    printf("\nAffichage du tableau :\n");
    for (i = 0; i < count; i++)
        printf("%s\n", tab_chaine[i]);

    // Libération des espaces alloués :
    for (i = 0; i < count; i++)
        free(tab_chaine[i]);
    free(tab_chaine);

    return 0;
}
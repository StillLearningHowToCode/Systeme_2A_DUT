#include <stdio.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Déclarations */
    int U[50][50]; /* matrice unitaire */
    int N;         /* dimension de la matrice unitaire */
    int I, J;      /* indices courants */

    /* Saisie des données */
    printf("Dimension de la matrice carrée (max.50) : ");
    scanf("%d", &N);

    /* Construction de la matrice carrée unitaire */
    for (I = 0; I < N; I++)
        for (J = 0; J < N; J++)
            if (I == J)
                U[I][J] = 1;
            else
                U[I][J] = 0;

    /* Edition du résultat */
    printf("Matrice unitaire de dimension %d :\n", N);
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
            printf("%7d", U[I][J]);
        printf("\n");
    }
    return 0;
}
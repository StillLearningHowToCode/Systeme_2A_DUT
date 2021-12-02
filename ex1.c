#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n;
    if ((n = fork()) == 0)
    {
        // Fils
        printf("Fils 1 : Processur fils avec PID : %i\n", getpid());
        printf("Fils 1 : Mon processus père est : %i\n", getppid());
        printf("\n");
        exit(0);
    }
    else
    {
        if ((n > 0))
        {
            // père
            printf("Père : Processur père avec PID : %i\n", getpid());
            printf("\n");

            // Création de fils
            int n2;
            if ((n2 = fork()) == 0)
            {
                printf("Fils 2 : Processur fils avec PID : %i\n", getpid());
                printf("Fils 2 : Mon processus père est : %i\n", getppid());
                printf("\n");
                exit(0);
            }
            else if (n2 < 0)
            {
                printf("Erreur\n");
                return -1;
            }

            //Temps d'attente
            sleep(1);

            int n3;
            if ((n3 = fork()) == 0)
            {
                printf("Fils 3 : Processur fils avec PID : %i\n", getpid());
                printf("Fils 3 : Mon processus père est : %i\n", getppid());
                printf("\n");
                exit(0);
            }
            else if (n3 < 0)
            {
                printf("Erreur\n");
                return -1;
            }
            sleep(1);
            printf("Père : Tout va bien\n");
        }
        else
        {
            // Erreur
            printf("Erreur de PID\n");
            return -1;
        }
    }
}
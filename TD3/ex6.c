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
        // Fils 1
        // exécution programme ex5
        execve("./ex5bis", NULL, NULL);
        printf("\n");
        // on attends on sait jamais
        sleep(1);
        exit(0);
    }
    else
    {
        if ((n > 0))
        {
            // père
            //printf("Père : Processus père avec PID : %i\n", getpid());

            // Création de fils
            int n2;
            if ((n2 = fork()) == 0)
            {
                // Fils 2
                // exécution programme ex5
                execve("./ex5", NULL, NULL);
                printf("\n");
                // on attends on sait jamais
                sleep(1);
                exit(0);
            }
            else if (n2 < 0)
            {
                printf("Erreur\n");
                return -1;
            }
        }
        else
        {
            // Erreur
            printf("Erreur de PID\n");
            return -1;
        }
    }
}
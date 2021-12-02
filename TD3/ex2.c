#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int n;
    if ((n = fork()) == 0)
    {
        // Fils 1
        printf("Fils 1 : Processus fils avec PID : %i\n", getpid());
        printf("Fils 1 : Mon processus père est : %i\n", getppid());
        printf("\n");
        exit(0);
        sleep(1);

        /*int n4;
        if ((n4 = fork()) == 0)
        {
            printf("Père Fils 1 : Processus fils avec PID : %i\n", getpid());
            printf("Père Fils 1  : Mon processus père est : %i\n", getppid());
            printf("\n");
            exit(0);
        }
        else if (n4 < 0)
        {
            printf("Erreur\n");
            return -1;
        }
        sleep(1);*/

    }
    else
    {
        if ((n > 0))
        {
            // Père
            printf("Père : Processus père avec PID : %i\n", getpid());
            printf("\n");

            int n2;
            if ((n2 = fork()) == 0)
            {
                // Fils
                printf("Fils 2 : Processus fils avec PID : %i\n", getpid());
                printf("Fils 2 : Mon processus père est : %i\n", getppid());
                printf("\n");
                exit(0);

                int n3;
                if ((n3 = fork()) == 0) 
                {
                    // Fils
                    printf("Fils 2 : Processus fils avec PID : %i\n", getpid());
                    printf("Fils 2 : Mon processus père est : %i\n", getppid());
                    printf("\n");
                    exit(0);
                }
                else 
                {
                    // Erreur
                    printf("Erreur de PID\n");
                    return -1;
                }

                sleep(1);
                
            }
            else if (n2 < 0)
            {
                printf("Erreur création fils 2\n");
                return -1;
            }

            //Temps d'attente
            sleep(1);
        }
        else
        {
            // Erreur
            printf("Erreur de PID\n");
            return -1;
        }
    }
}
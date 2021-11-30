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
        printf("Fils : Processur fils avec PID : %i\n", getpid());
        printf("Fils : Mon processus père est : %i\n", getppid());
        printf("\n");
    }
    else
    {
        if ((n > 0))
        {
            printf("Père : Processur père avec PID : %i\n", getpid());
            printf("\n");
        }
        else
        {
            printf("Erreur de PID\n");
            return -1;
        }
    }
    //printf("Mon PID est %i\n", getpid());
}
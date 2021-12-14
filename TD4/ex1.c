/* Proposer un programme c qui attrape tous les signaux. Dès qu’il attrape un signal, il
* affiche le signal reçu.
* Utiliser la commande kill dans le terminal sous le format suivant : kill –signal pid. (Essayez les
* commandes ctrl+c, ctrl+z, de redimensionner la fenêtre...)*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void capturerSignal(const int sig)
{
    printf("\n Signal %d reçu\n", sig);
}

int main(int argc, char const *argv[])
{
    printf("Voici mon pid : %d\n", getpid());

    for (int i = 1; i < NSIG; ++i)
    {
        if (signal(i, capturerSignal) == SIG_ERR)
        {
            printf("Erreur attente signal %d\n", i);
        }
    }
    while (1);

    return 0;
}
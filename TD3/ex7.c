#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    // Variables
    char nom[50];
    char res;

    printf("Saisissez le nom de votre executable : ");
    res = scanf("%49s", nom);
    res = trim(res);
    res = strcat("./", res);

    // %s pour lire une chaine de caractères
    // %c pour lire un caractère
    printf("Très bien ça fonctionne pas...\n Nom du prog : %s\n", nom);

    execve(res, NULL, NULL);
}
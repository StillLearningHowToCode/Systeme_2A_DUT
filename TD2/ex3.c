#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // Variables
    int taille = 10;
    int decalage = 15;
    int fichier, offset;
    char buffer[taille + 1];

    // Vérification du nombre d'arguments (On en attends 1)
    if (argc != 2)
    {
        // Message d'erreur
        printf("Veuillez entrer un argument\n");
        return -1;
    }

    // Ouverture de fichier
    printf("Ouverture du fichier : %s\n", argv[1]);
    if (fichier = open((argv[1], O_RDONLY)) < 0)
    {
        // Message d'erreur
        printf("Erreur ouverture\n");
        return -1;
    }

    // Offset
    if ((offset = lseek(fichier, decalage, SEEK_SET)) != decalage)
    {
        printf("Erreur déplacement\n");
        return -1;
    }

    // Lecture
    if (read(fichier, buffer, taille) < 0)
    {
        printf("Erreur lecture\n");
        return -1;
    }

    // Retour du résultat
    printf("Lecture de : %s\n", buffer);

    // Fermeture
    close(fichier);

    return 0;
}
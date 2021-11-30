#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* 
* argv = adresse d'un tableau
* argc = entier qui indique le nombre de chaines contenues dans le tableau
*/

int main(int argc, char const *argv[])
{
    // Définition des variables
    int fichier1, fichier2, nombreLecture, nombreEcriture;
    char buffer[BUFSIZ];

    // Vérification du nombre d'arguments (On en attends 2)
    if (argc != 3)
    {
        // Message d'erreur
        printf("Veuillez entrer 2 arguments\n");
        return -1;
    }

    // Ouverture de fichier
    printf("Ouverture du fichier : %s\n", argv[1]);
    if (fichier1 = open((argv[1], O_RDONLY)) < 0)
    {
        // Message d'erreur
        printf("Erreur ouverture\n");
        return -1;
    }

    // Création de fichier
    printf("Création du fichier %s\n", argv[2]);
    if ((fichier2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY)) < 0)
    {
        // Message d'erreur
        printf("Erreur ouverture\n");
        return -1;
    }

    // Copie des fichiers
    printf("Copie fichiers\n");
    while ((nombreLecture = read(fichier1, buffer, BUFSIZ)) > 0)
    {
        if ((nombreEcriture = read(fichier2, buffer, nombreLecture)) != nombreLecture)
        {
            // Message d'erreur
            printf("Erreur écriture\n");
            return -1;
        }
    }

    // Fermeture des fichiers
    close(fichier1);
    close(fichier2);

    return 0;
}
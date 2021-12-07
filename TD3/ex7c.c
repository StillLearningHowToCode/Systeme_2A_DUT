#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 2
#define MAX 10

int compteur = 0;
char programme[BUFSIZ];
char *arguments[] = {NULL};
char *environnement[] = {NULL};


void erreur(const char *message) {
    printf("Erreur durant : %s\n", message);
    exit(EXIT_FAILURE);
}

void saisirProgramme() {
    printf("Saisir le nom d'un programme\n");
    scanf("%s", programme);
}

int testerFichierExiste(const char *lien) {
    struct stat statsFichier;
    int existe = stat(lien, &statsFichier);

    return existe == 0;
}

void executerProgramme() {
    int pid;

    if (testerFichierExiste(programme)) {
        switch (pid = fork()) {
            case -1:
                erreur("fork");
            case 0:
                printf("Execution de '%s'\n", programme);
                execve(programme, arguments, environnement);
                exit(EXIT_SUCCESS);
        }
    } else {
        printf("Le fichier '%s' n'existe pas.\n", programme);
    }
}

int main(const int argc, char const *argv[]) {
    while (compteur < MAX) {
        saisirProgramme();

        executerProgramme();
        compteur++;
        wait(NULL);
        /*
        * wait(NULL) will block parent process until any of its children has finished. 
        * If child terminates before parent process reaches wait(NULL) then the child process turns to a zombie process until its parent waits on it and its released from memory.
        *
        * If parent process doesn't wait for its child, and parent finishes first, then the child process becomes orphan and is assigned to init as its child. 
        * And init will wait and release the process entry in the process table.
        * 
        * In other words: parent process will be blocked until child process returns an exit status to the operating system which is then returned to parent process. 
        * If child finishes before parent reaches wait(NULL) then it will read the exit status, release the process entry in the process table and continue execution until it finishes as well.
        */
    }

    printf("Je suis ton père.\nFin du programme exo7\n");
    return EXIT_SUCCESS;
}
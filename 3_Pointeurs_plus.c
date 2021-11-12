/*
* Notes : 
* p_res : désigne la variable
* &p_res : désigne l'@dresse de la variable
* Si on place : * devant variable stockée = valeur du pointeur
*/

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <fcntl.h>  

// Définition 
/* /!\ 1e chose à définir /!\*/
typedef struct {
    int x;
    int y;
    int z;
} coordonnees;

// Entetes 
void initialize(coordonnees *point);
void affichage(coordonnees *point);
void multiplication(coordonnees *point);
void addition(coordonnees *point);

// Main
int main(int argc, char *argv[] ) { 
    coordonnees point;
    initialize(&point);
    affichage(&point);
    printf("\n");
    multiplication(&point);
    addition(&point);
}

// Fonction initaliser
void initialize(coordonnees *point) {
    point->x = 10;
    point->y = 5;
    point->z = 2;
}

// Fonction affichage valeurs x, y & z
void affichage(coordonnees *point) {
    printf("Valeur de x : %d", point->x);
    printf("\nValeur de y : %d", point->y);
    printf("\nValeur de z : %d", point->z);
}

// Fonction Multiplication
// Multiplie x et y puis stocke le contenu dans z
void multiplication(coordonnees *point) {
    point->z = point->x * point->y;
    printf("\n");
    printf("Valeurs après la multiplication : \n");
    affichage(point);
}

// Fonction Addition
// Additionne y et z puis stocke le contenu dans z
void addition(coordonnees *point) {
    point->z = point->y + point->z;
    printf("\n");
    printf("\nValeurs après l'addition : \n");
    affichage(point);
}
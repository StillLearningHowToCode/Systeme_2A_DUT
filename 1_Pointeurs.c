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

// Attention à bien définir les entetes
void Addition(int* p_nb1, int* p_nb2, int* p_res);
void Soustraction(int* p_nb1, int* p_nb2, int* p_res);
void Multiplication(int* p_nb1, int* p_nb2, int* p_res);

int main(int argc, char *argv[] ) { 
    int x = 2;
    int y = 1;
    int z = 0;

    Addition(&x, &y, &z);
    printf("Addition : %d\n", z);

    Soustraction(&x, &y, &z);
    printf("Soustraction : %d\n", z);

    Multiplication(&x, &y, &z);
    printf("Multiplication : %d\n", z);
}

void Addition(int* p_nb1, int* p_nb2, int* p_res) {
    *p_res = *p_nb1 + *p_nb2;
}

void Soustraction(int* p_nb1, int* p_nb2, int* p_res) {
    *p_res = *p_nb1 - *p_nb2;
}

void Multiplication(int* p_nb1, int* p_nb2, int* p_res) {
    *p_res = *p_nb1 * *p_nb2;
}

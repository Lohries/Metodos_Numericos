#include <stdio.h>
#include <stdlib.h>

void aloca(int casas, int **p);

int main () {
    int casas;
    int *ptr = NULL;
    printf("Digite quantas casas vai ter seu numero binario");
    scanf("%i", &casas);
    aloca(casas, &ptr);



}

void aloca(int casas, int **p) {


}
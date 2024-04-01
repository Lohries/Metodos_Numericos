#include <stdio.h>
#include <stdlib.h>

void aloca(int casas, int **p);

int main () {
    int casas;
    int *ptr = NULL;
    printf("Digite quantas casas vai ter seu numero binario");
    scanf("%i", &casas);
    aloca(casas, &ptr);
    for (int i = 0; i < casas; i++, ptr++) {
        printf("Insira um numero: ");
        scanf("%i", &ptr);

    }
    for (int i = 0; i < casas; i++, ptr--) {
        if (*ptr == 1)
            *ptr = 0;
        else 
            *ptr = 1;
    }
    ptr = ptr + (sizeof(int) * casas);
    for (int i = 0; i < casas; i++, ptr--) {
        if (*ptr == 1)
            *ptr += 1;
        else 
            printf("Nada");
    }
    
    free(ptr);

}

void aloca(int casas, int **p) {
    *p = ((int*)malloc(casas * sizeof(int)));
    if (*p == NULL)
        exit(1);
}
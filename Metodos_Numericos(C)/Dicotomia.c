#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void aloca(float **p, int grau);


int main () {
    int grau;
    float *ptr = NULL;
    float erro, intervaloA, intervaloB;
    printf("Digite o grau do polinomio: ");
    scanf("%f", &grau);
    aloca(&ptr, grau);
    for (int i = 0; i < grau; ptr++) {
        printf("Digite os ceoficientes do mqior grqu qo menor");
        scanf("%f", ptr);
    }
    printf("Digite o valor do erro: ");
    scanf("%f", &erro);
    printf("Digite o intervalo de x: ");
    scanf("%f", &intervaloA);
    scanf("%f", &intervaloB);

}

void aloca (float **p, int grau) {
    *p = ((float)realloc(*p, grau * sizeof(float)))
    if (*p == NULL)
        exit(1);

}

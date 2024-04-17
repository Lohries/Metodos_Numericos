#include <stdio.h>
#include <stdlib.h>

void aloca(float **x, float **y, int tam);
void preenchimento(float **p_x, float **p_y, int n);

int main() {
    int pontos, grau, cont, i, j;
    float Px, valorCalcular;
    char resp;

    printf("Digite o grau da função que deseja obter: ");
    scanf("%i", &grau);
   
    pontos = grau + 1;
    
    float *valoresX = NULL;
    float *valoresFX = NULL;
    aloca(&valoresX, &valoresFX, pontos);

    preenchimento(&valoresX, &valoresFX, pontos);


    do {
        printf("Digite o valor que deseja calcular: ");
        scanf("%f", &valorCalcular);

        Px = 0;
        
        for (i = 0; i < pontos; i++) {
            float Li = 1.0;
            for (j = 0; j < pontos; j++) {
                if (j != i) {
                    Li *= (valorCalcular - valoresX[j]) / (valoresX[i] - valoresX[j]);
                }
            }
            Px += Li * valoresFX[i];
        }

        printf("O valor interpolado é: %f\n", Px);

        fflush(stdin);
        printf("Deseja calcular outro valor (s/n)? ");
        scanf(" %c", &resp); 

    } while (resp == 's' || resp == 'S');


    free(valoresX);
    free(valoresFX);

    return 0;
}

void aloca(float **x, float **y, int tam) {
    *x = (float*)malloc(tam * sizeof(float));
    *y = (float*)malloc(tam * sizeof(float));
    if (*x == NULL || *y == NULL) {
        printf("Falha em alocar");
        exit(1);
    }
}

void preenchimento(float **p_x, float **p_y, int n) {
    for (int cont = 0; cont < n; cont++) {
        printf("Digite o valor de X%d: ", cont);
        scanf("%f", &(*p_x)[cont]);
        printf("Digite o valor de f(X%d): ", cont);
        scanf("%f", &(*p_y)[cont]);
    }
}

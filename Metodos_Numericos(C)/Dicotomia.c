//Kauan Victor Marques RA:235003 Luis Henrique Telo Ladeira Mota RA:235428 Patrick Vieira Leo RA: 234868

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculando_k(float precisao_k, float intervaloA_k, float intervaloB_k);
void aloca(int grau_f, float **p);
void preenchimento(float **p, int grau_p);
int dicotomia(float intervaloA_D, float intervaloB_D, float **p, int grau_D, float intervaloM);

int main() {
    int grau, numero_interar, flag_controle;
    float precisao, intervaloA, intervaloB, intervalo_main;
    float *ptr = NULL;
    printf("\nInsira o grau do polinomio: ");
    scanf("%i", &grau);
    printf("\nInsira a precisao: ");
    scanf("%f", &precisao);
    printf("\nInsira menor extremo: ");
    scanf("%f", &intervaloA);
    printf("\nInsira o extremo maior: ");
    scanf("%f", &intervaloB);
    numero_interar = calculando_k(precisao, intervaloA, intervaloB);
    intervalo_main = intervaloB - intervaloA;
    float intervaloM = (intervaloA + intervaloB)/2;
    printf("\nObtendo a funcao do usuario....\n");
    aloca(grau, &ptr);
    preenchimento(&ptr, grau);

    while(numero_interar > 0 && intervalo_main > precisao) { // Correção aqui
        flag_controle = dicotomia(intervaloA, intervaloB, &ptr, grau, intervaloM);
        printf("\n%f\n", intervaloM);
        if (flag_controle == -1) { // Correção aqui
            intervaloA = intervaloM;
        }
        else if (flag_controle == 1) { // Correção aqui
            intervaloB = intervaloM;
        }
        else { // Correção aqui
            break; // Se flag_controle for 0, já encontramos a raiz
        }
        intervalo_main = intervaloB - intervaloA; // Atualização da condição de parada
        intervaloM = (intervaloA + intervaloB) / 2;
        numero_interar--; 
    }
    printf("\nFINALIZADA A DICOTOMIA");
    printf("\nRESULTADO FINAL %f", intervaloM);

    free(ptr); 
    return 0;
}

int calculando_k(float precisao_k, float intervaloA_k, float intervaloB_k) {
    double k;
    k = (log(intervaloB_k - intervaloA_k) - log(precisao_k)) / log(2);
    printf("O valor de k foi de %f", round(k));
    return round(k);
}

void aloca(int grau_f, float **p) {
    *p = (float*)realloc(*p, (grau_f + 1) * sizeof(float));
    if (*p == NULL) {
        printf("\nErro ao alocar memória!\n");
        exit(1);
    } else {
        printf("\nContinuando...\n");
    }
}

void preenchimento(float **p, int grau_p) {
    for (int i = grau_p; i >= 0; i--) {
        printf("\nDigite o coeficiente para o termo de grau %i: ", i);
        scanf("%f", &(*p)[i]);
    }
}

int dicotomia(float intervaloA_D, float intervaloB_D, float **p, int grau_D, float intervaloM) {
    float funcaoA = 0;
    float funcaoB = 0;
    float funcaoM = 0;
    printf("\n%f\n", intervaloA_D);
    printf("\n%f\n", intervaloB_D);
    
    for (int i = grau_D; i >= 0; i--) {
        funcaoA += ((*p)[i] * pow(intervaloA_D, i));
        funcaoB += ((*p)[i] * pow(intervaloB_D, i)); 
        funcaoM += ((*p)[i] * pow(intervaloM, i)); 
    }
    printf("\nFuncaoA: %f", funcaoA);
    printf("\nFuncaoB: %f", funcaoB);
    printf("\nFuncaoM: %f", funcaoM);
    if (funcaoA * funcaoM > funcaoB * funcaoM) {
        return -1; // Mover para a esquerda
    }
    else if (funcaoA * funcaoM < funcaoB * funcaoM) {
        return 1; // Mover para a direita
    }
    else {
        return 0; // Encontramos a raiz
    }  
}

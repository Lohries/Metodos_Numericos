#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculando_k(float precisao_k, float intervaloA_k, float intervaloB_k);
void aloca(int grau_f, float **p);
void preenchimento(float **p, int grau_p);
int dicotomia(float intervaloA_D, float intervaloB_D, float **p, int grau_D, float intervaloM);

int main() {
    int grau, numero_interar, flag_controle;
    float precisao, intervaloA, intervaloB, intervalo_main, intervaloM;
    char controle;

    do {
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
        intervaloM = (intervaloA + intervaloB) / 2;

        float *ptr = NULL;
        aloca(grau, &ptr);
        preenchimento(&ptr, grau);

        while (numero_interar > 0 && intervalo_main > precisao) {
            flag_controle = dicotomia(intervaloA, intervaloB, &ptr, grau, intervaloM);
            if (flag_controle == -1) {
                intervaloA = intervaloM;
            } else if (flag_controle == 1) {
                intervaloB = intervaloM;
            } else {
                break;
            }
            intervalo_main = intervaloB - intervaloA;
            intervaloM = (intervaloA + intervaloB) / 2;
            numero_interar--;
        }

        printf("\nRESULTADO FINAL: %f\n", intervaloM);
        printf("\nDigite 's' para continuar e 'n' para parar: ");
        scanf(" %c", &controle); 

        free(ptr);
    } while (controle == 's' || controle == 'S');

    return 0;
}

int calculando_k(float precisao_k, float intervaloA_k, float intervaloB_k) {
    double k;
    k = (log(intervaloB_k - intervaloA_k) - log(precisao_k)) / log(2);
    return round(k);
}

void aloca(int grau_f, float **p) {
    *p = (float*)malloc((grau_f + 1) * sizeof(float));
    if (*p == NULL) {
        printf("\nErro ao alocar memória!\n");
        exit(1);
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

    for (int i = grau_D; i >= 0; i--) {
        funcaoA += ((*p)[i] * pow(intervaloA_D, i));
        funcaoB += ((*p)[i] * pow(intervaloB_D, i));
        funcaoM += ((*p)[i] * pow(intervaloM, i));
    }

    if (funcaoA * funcaoM > funcaoB * funcaoM) {
        return -1;
    } else if (funcaoB * funcaoM > funcaoA * funcaoM) {
        return 1;
    } else {
        return 0;
    }
}

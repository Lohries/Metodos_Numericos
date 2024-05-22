#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void aloca_pontos(float **x_a, float **y_a, float **xy_a, float **square, int points_A) {
    *x_a = (float*)malloc(sizeof(float) * points_A);
    *y_a = (float*)malloc(sizeof(float) * points_A);
    *xy_a = (float*)malloc(sizeof(float) * points_A);
    *square = (float*)malloc(sizeof(float) * points_A);
    if (*x_a == NULL || *y_a == NULL || *xy_a == NULL || *square == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
}

int main() {
    int points;
    printf("Insira quantos pontos existem: ");
    scanf("%i", &points);

    float sumx = 0;
    float sumy = 0;
    float sumxy = 0;
    float sum2 = 0;
    float slope;
    float intercept;

    float *x = NULL;
    float *y = NULL;
    float *xy = NULL;
    float *square = NULL;

    aloca_pontos(&x, &y, &xy, &square, points);

    for (int i = 0; i < points; i++) {
        printf("Insira o valor do x%i: ", i + 1);
        scanf("%f", &x[i]);
        square[i] = pow(x[i], 2);
        printf("Insira o valor do y%i: ", i + 1);
        scanf("%f", &y[i]);
        xy[i] = x[i] * y[i];
    }

    for (int j = 0; j < points; j++) {
        sumx += x[j];
        sumy += y[j];
        sumxy += xy[j];
        sum2 += square[j];
    }

    float denominator = points * sum2 - pow(sumx, 2);
    if (denominator == 0) {
        printf("Erro: Divisão por zero. Não é possível calcular a reta.\n");
        free(x);
        free(y);
        free(xy);
        free(square);
        return 1;
    }

    slope = (points * sumxy - sumx * sumy) / denominator;
    intercept = (sumy - slope * sumx) / points;

    printf("A reta é y = %.2fx + %.2f\n", slope, intercept);

    free(x);
    free(y);
    free(xy);
    free(square);

    return 0;
}

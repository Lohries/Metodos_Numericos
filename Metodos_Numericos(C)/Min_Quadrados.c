#include <stdio.h>
#include <math.h>

int main () {
    int points;
    printf("Insira quantos pontos existem: ");
    scanf("%i", &points);

    float x[points];
    float y[points];
    float xy[points];
    float square[points];
    float sumx = 0;
    float sumy = 0;
    float sumxy = 0;
    float sum2 = 0;
    float slope;
    float intercept;

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
        return 1;
    }

    slope = (points * sumxy - sumx * sumy) / denominator;
    intercept = (sumy - slope * sumx) / points;

    printf("A reta é y = %.2fx + %.2f\n", slope, intercept);

    return 0;
}

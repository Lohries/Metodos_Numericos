#include <stdio.h>
#include <math.h>

float bhaskara(float a, float b, float c);

int main () {
    int grau;
    float coefA, coefB, coefC;
    printf("Digite qual o grau do seu polinomio: ");
    scanf("%i", &grau);
    bhaskara(coefA, coefB, coefC);

}

float bhaskara(float a, float b, float c) {
    float delta; 
    printf("Coeficiente A: ");
    scanf("%f", &a);
    printf("Coeficiente B: ");
    scanf("%f", &b);
    printf("Coeficiente C: ");
    scanf("%f", &c);
    delta = pow(b, 2) - (4 * a * c);
    


}
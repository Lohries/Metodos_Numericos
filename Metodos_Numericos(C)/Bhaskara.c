#include <stdio.h>
#include <math.h>

float delta(float coefA, float coefB, float coefC);

int main () {
    int grau;
    float a, b, c;
    float x1, x2; 
    printf("Coeficiente A: ");
    scanf("%f", &a);
    printf("Coeficiente B: ");
    scanf("%f", &b);
    printf("Coeficiente C: ");
    scanf("%f", &c);
    float delta_main = delta(a, b, c);
    x1 = ((-1)*b + sqrt(delta_main))/(4*a);
    x2 = ((-1)*b - sqrt(delta_main))/(4*a);
    printf("Os valores de x sao %2.f e %2.f", x1, x2);
}

float delta(float coefA, float coefB, float coefC) {
    float delta;
    delta = pow(coefB, 2) - (4 * coefA * coefC);
    return delta;
   
}
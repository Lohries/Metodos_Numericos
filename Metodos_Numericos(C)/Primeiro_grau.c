#include <stdio.h>
#include <math.h>

int main () {
    float a, b;
    float x;
    printf("Insert the 'a' parameter, that multiply the variable:");
    scanf("%f", &a);
    printf("Insert the 'b' parameter:");
    scanf("%f", &b);
    b = (-1) * b;
    x = b/a;
    printf("The answer is %2.f", x);

}
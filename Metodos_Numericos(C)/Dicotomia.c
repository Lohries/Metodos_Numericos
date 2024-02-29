#include <stdio.h>
#include <math.h>

float sine();
float cossine();
float tangent();
float none(int grau, float pointA_x, float pointB_x);
float get_coef();


int main () {
    int grau, model;
    float pointA_x, pointB_x;
    float pointA_y, pointB_y;
    char flag;
    printf("Insert based on the type of function (1-sin  2-cos  3-tg  4-None of thos)");
    scanf("%i", &model);
    if (model == 1) {
        printf("The variable is inside of the sin");

    }
    else if (model == 2) {
        printf("The variable is inside of the cos");

    }
    else if (model == 3) {
        printf("The variable is inside of the tg");

    }
    else {
        none(grau, pointA_x, pointB_x);

    }
  

}

float none(int grau, float pointA_x, float pointB_x) {
    printf("Insert the biggest expoent in your equation: ");
    scanf("%i", &grau);
    printf("Insert the point A, x");
    scanf("%f", &pointA_x);
    printf("Insert the point B, x ");
    scanf("%f", &pointB_x);
    float a, b, c, d;
    float function1, function2;
    float k;
    float x;
    if (grau == 2) {
        a = get_coef();
        b = get_coef();
        c = get_coef();
        x = pointA_x;
        function1 = (((a * pow(x, grau))) + (b * pow(x, (grau-1))) + (c * pow(x, grau-2)));
        x = pointB_x;
        function2 = (((a * pow(x, grau)) + (b * pow(x, (grau-1))) + (c * pow(x, grau-2))));
        k = function1 * function2;
    }

    else if (grau == 3) {
        a = get_coef();
        b = get_coef();
        c = get_coef();
        d = get_coef();
        x = pointA_x;
        function1 = ((a * pow(x, grau)) + (b * pow(x, (grau-1))) + (c * pow(x, grau-2)) + (d * pow(x, grau-3)));
        x = pointB_x;
        function2 = ((a * pow(x, grau)) + (b * pow(x, (grau-1))) + (c * pow(x, grau-2)) + (d * pow(x, grau-3)));
        k = function1 * function2;


    }


}

float get_coef() {
   
    float coef;
    printf("Insert the coef: ");
    scanf("%f", &coef);
    return coef;  
}


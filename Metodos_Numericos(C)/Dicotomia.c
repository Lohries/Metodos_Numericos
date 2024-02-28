#include <stdio.h>
#include <math.h>

float sine();
float cossine();
float tangent();
float none(int grau, float pointA_x, float pointA_y, float pointB_x, float pointB_y);
float get_coef();


int main () {
    int grau, model;
    float pointA_x, pointB_x;
    float pointA_y, pointB_y;
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
        none(grau, pointA_x, pointA_y, pointB_x, pointB_y);

        
    }
  

}

float none(int grau, float pointA_x, float pointA_y, float pointB_x, float pointB_y) {
    printf("Insert the biggest expoent in your equation: ");
    scanf("%i", &grau);
    printf("Insert the point A, x and y in order");
    scanf("%f, %f", &pointA_x, &pointA_y);
    printf("Insert the point B, x and y in order");
    scanf("%f, %f", &pointB_x, &pointB_y);
    float a, b, c, d;
    float function;
    float x;
    if (grau == 2) {
        a = get_coef();
        b = get_coef();
        c = get_coef();
        function = (((a * pow(x, grau))) + (b * pow(x, (grau-1))) + (c * pow(x, grau-2)));
    
    }

    else if (grau == 3) {
        a = get_coef();
        b = get_coef();
        c = get_coef();
        d = get_coef();
        function = ((a * pow(x, grau)) + (b * pow(x, (grau-1))) + (c * pow(x, grau-2)) + (d * pow(x, grau-3)));
        
    }


}

float get_coef() {
   
    float coef;
    printf("Insert the coef: ");
    scanf("%f", &coef);
    return coef;  
}


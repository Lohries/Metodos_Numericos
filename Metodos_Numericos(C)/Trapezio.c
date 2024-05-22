#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// Protótipo das funções
float funcao(float valor);

int grau;
float multi[7]; 

int main()
{
    int i;
   
    printf("Informe o grau da funcao (2 a 10): ");
    scanf("%i", &grau);

    
    for (i = 0; i <= grau; i++)
    {
        printf("Informe o fator multiplicador de x^%i: ", i);
        scanf("%f", &multi[i]);
    }

 
    printf("A funcao recebida foi: ");
    for (i = 0; i <= grau; i++)
    {
        printf("%.2fx^%i", multi[i], i);
        if (i < grau)
            printf(" + ");
        else
            printf(" = 0");
    }


    float a, b;
    int n;

   
    printf("\n\nInforme o limite inferior (a): ");
    scanf("%f", &a);
    printf("Informe o limite superior (b): ");
    scanf("%f", &b);
    printf("Informe o numero de subintervalos (n): ");
    scanf("%d", &n);

    
    float h = (b - a) / n;
    float integral = 0.0;

  
    for (i = 0; i <= n; i++)
    {
        float x = a + i * h;
        if (i == 0 || i == n)
        {
            integral += funcao(x);
        }
        else
        {
            integral += 2 * funcao(x);
        }
    }
    integral = (h / 2) * integral;

   
    printf("\nA integral da funcao no intervalo [%.2f, %.2f] e aproximadamente: %.4f\n", a, b, integral);



    system("pause");
    return 0;
}


float funcao(float valor)
{
    int i;
    float resultado;
    resultado = 0;

    for (i = 0; i <= grau; i++)
    {
        resultado = resultado + multi[i] * pow(valor, i);
    }

    return resultado;
}

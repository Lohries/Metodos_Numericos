#include <stdio.h>
#include <stdlib.h>

int main() {
    int pontos, grau, cont, i, j;
    float Px, valorCalcular;
    char resp;

    printf("Digite o grau da função que deseja obter: ");
    scanf("%i", &grau);
    // Obtendo o número de pontos a partir do grau indicado
    pontos = grau + 1;
    
    // Arrays para armazenar os valores de x e f(x)
    float valoresX[pontos];
    float valoresFX[pontos];

    // Recebendo os valores da tabela (valores de x e f(x))
    for (cont = 0; cont < pontos; cont++) {
        printf("Digite o valor de X%d: ", cont);
        scanf("%f", &valoresX[cont]);
        printf("Digite o valor de f(X%d): ", cont);
        scanf("%f", &valoresFX[cont]);
    }

    do {
        printf("Digite o valor que deseja calcular: ");
        scanf("%f", &valorCalcular);

        Px = 0;
        // Implementação do cálculo do Teorema de Lagrange
        for (i = 0; i < pontos; i++) {
            float Li = 1.0;
            for (j = 0; j < pontos; j++) {
                if (j != i) {
                    Li *= (valorCalcular - valoresX[j]) / (valoresX[i] - valoresX[j]);
                }
            }
            Px += Li * valoresFX[i];
        }

        printf("O valor interpolado é: %f\n", Px);

        fflush(stdin);
        printf("Deseja calcular outro valor (s/n)? ");
        scanf(" %c", &resp); // Note o espaço antes de %c para consumir o caractere de nova linha anterior

    } while (resp == 's' || resp == 'S');

    return 0;
}

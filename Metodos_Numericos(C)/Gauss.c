#include <stdio.h>

int main () {
    int variable, equations;

    printf("Insira quantas variaveis existem: ");
    scanf("%i", &variable);

    printf("Insira quantas equacoes existem: ");
    scanf("%i", &equations);

    

    float matrix[equations][variable + 1];
    float multiplier;


    for (int i = 0; i < equations; i++) {
        for(int j = 0; j < variable + 1; j++) {
            printf("Insira o elemento %i da %i linha: ", j + 1, i + 1);
            scanf("%f", &matrix[i][j]);
        }
    }


    for (int i = 0; i < equations; i++) {
     
        for (int k = i + 1; k < equations; k++) {
            if (matrix[i][i] < matrix[k][i]) {
                for (int j = 0; j <= variable; j++) {
                    float temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }

        
        for (int k = i + 1; k < equations; k++) {
            multiplier = matrix[k][i] / matrix[i][i];
            for (int j = 0; j <= variable; j++) {
                matrix[k][j] -= multiplier * matrix[i][j];
            }
        }
    }

  
    float solution[variable];
    for (int i = equations - 1; i >= 0; i--) {
        solution[i] = matrix[i][variable];
        for (int j = i + 1; j < variable; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    printf("As soluções são:\n");
    for (int i = 0; i < variable; i++) {
        printf("x%d = %0.2f\n", i + 1, solution[i]);
    }

    return 0;
}

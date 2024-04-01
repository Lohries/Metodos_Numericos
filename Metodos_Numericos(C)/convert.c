#include <stdio.h>
#include <math.h>

int main() {
    int type;
    int decimal_number;
    int rest;
    int result[16]; 
    int input_binary[8];
    int output_binary = 0; 
    int i = 0, j = 0, k = 0;

    do {
        printf("Calculating the conversion, 1-Decimal->Binary  2-Binary->Hexadecimal  3-Decimal->Hexadecimal 4-Binary->Decimal: ");
        scanf("%d", &type);

        if (type == 1) {
            printf("Insert the decimal number: ");
            scanf("%d", &decimal_number);

            i = 0; // Reset i for binary conversion
            do {
                rest = decimal_number % 2;
                result[i] = rest;
                decimal_number /= 2; // Divide by 2 for binary conversion
                i++;
            } while (i < 8);

            // Print binary result
            printf("Binary: ");
            for (i = i - 1; i >= 0; i--) {
                printf("%d", result[i]);
            }
            printf("\n");
            
        } else if (type == 2) {




           
        } else if (type == 3) {
            printf("Insert the decimal number: ");
            scanf("%d", &decimal_number);

            k = 0; // Reset k for hexadecimal conversion
            do {
                rest = decimal_number % 16;
                result[k] = rest;
                decimal_number /= 16; // Divide by 16 for hexadecimal conversion
                k++;
            } while (k < 16);

            // Print hexadecimal result
            printf("Hexadecimal: ");
            for (k = k - 1; k >= 0; k--) {
                if (result[k] < 10) {
                    printf("%d", result[k]);
                } else {
                    printf("%c", result[k] - 10 + 'A');
                }
            }
            printf("\n");
        } else if (type == 4) {
            printf("Insert the binary number (8 bits): ");
            for (j = 0; j < 8; j++) {
                scanf("%d", &input_binary[j]);
                output_binary = output_binary * 2 + input_binary[j];
            }

            // Print decimal result
            printf("Decimal: %d\n", output_binary);
        }
    } while (type >= 1 && type <= 4);

    return 0;
}

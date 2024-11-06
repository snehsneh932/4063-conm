#include <stdio.h>
#include <math.h>
#include <string.h>

long long int itob(int x) {
    int p = 1;
    long long int b = 0;
    while (x != 0) {
        int r = x % 2;
        b = b + r * p;
        p *= 10;
        x /= 2;
    }
    return b;
}

void dtob(float x, char* binary_frac) {
    int int_part = (int)x;
    float frac_part = x - int_part;
    int i = 0;

    long long int binary_int = itob(int_part);
    char int_part_binary[64];
    sprintf(int_part_binary, "%lld", binary_int);

    strcpy(binary_frac, int_part_binary);
    strcat(binary_frac, ".");

    while (frac_part > 0 && i < 8) {
        frac_part *= 2;
        int bit = (int)frac_part;
        if (bit == 1) {
            binary_frac[strlen(binary_frac)] = '1';
            frac_part -= bit;
        } else {
            binary_frac[strlen(binary_frac)] = '0';
        }
        i++;
    }
    binary_frac[strlen(binary_frac)] = '\0';
}

float btof(const char* binary_frac) {
    int int_part = 0;
    float frac_part = 0.0;
    int i = 0;
    
    while (binary_frac[i] != '.' && binary_frac[i] != '\0') {
        int_part = int_part * 2 + (binary_frac[i] - '0');
        i++;
    }

    if (binary_frac[i] == '.') {
        i++;
    }

    float frac_power = 0.5;
    while (binary_frac[i] != '\0') {
        if (binary_frac[i] == '1') {
            frac_part += frac_power;
        }
        frac_power /= 2;
        i++;
    }

    return int_part + frac_part;
}

int main() {
    float x;
    char binary_frac[64] = "",bi_fr[34];
    printf("Enter a decimal number (e.g., 2345.67): ");
    scanf("%f", &x);
    dtob(x, binary_frac);
    printf("Binary representation: %s\n", binary_frac);
    printf("Enter a float string in binary: ");
    scanf("%s", &bi_fr);
    float decimal_value = btof(bi_fr);
    printf("Converted back to decimal: %.6f\n", decimal_value);
    return 0;
}
// output 
//Enter a decimal number (e.g., 2345.67): 24.25
//Binary representation: 11000.01
//Enter a float string in binary: 11000.01
//Converted back to decimal: 24.250000
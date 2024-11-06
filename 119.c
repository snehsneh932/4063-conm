#include <stdio.h>

int main() {
    // Declare floating-point variables
    float num1 = 3.14f;
    double num2 = 6.283185307;
    long double num3 = 1.6180339887498948482L;
    
    // Print the floating-point numbers
    printf("Float: %.2f\n", num1);
    printf("Double: %.10lf\n", num2);
    printf("Long double: %.20Lf\n", num3);
    
    // Perform basic arithmetic operations
    float sum = num1 + num2;
    float difference = num2 - num1;
    float product = num1 * num2;
    float quotient = num2 / num1;
    
    // Print the results of arithmetic operations
    printf("\nArithmetic operations:\n");
    printf("Sum: %.2f\n", sum);
    printf("Difference: %.2f\n", difference);
    printf("Product: %.2f\n", product);
    printf("Quotient: %.2f\n", quotient);

    return 0;
}
// output 
// Float: 3.14
// Double: 6.2831853070
// Long double: 1.61803398874989484820

// Arithmetic operations:
// Sum: 9.42
// Difference: 3.14
// Product: 19.74
// Quotient: 2.00

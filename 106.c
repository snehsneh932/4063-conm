// Birge vieta
#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 10
#define EPSILON 0.001

void birgeVieta(double coeffs[], int degree, double initial_guess) {
    double b[MAX_DEGREE + 1], c[MAX_DEGREE + 1];
    double x = initial_guess, prev_x;
    int iteration = 0;

    do {
        prev_x = x;
        b[degree] = coeffs[degree];
        c[degree] = coeffs[degree];

        for (int i = degree - 1; i >= 0; i--) {
            b[i] = coeffs[i] + x * b[i + 1];
            c[i] = b[i] + x * c[i + 1];
        }
        
        x = x - b[0] / c[1];
        iteration++;
        printf("Iteration %d: x = %.6f\n", iteration, x);
    } while (fabs(x - prev_x) > EPSILON);

    printf("The root is: %.6f\n", x);
}

int main() {
    int degree;
    double coeffs[MAX_DEGREE + 1], initial_guess;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter the coefficients of the polynomial (highest degree first):\n");
    for (int i = degree; i >= 0; i--) {
        scanf("%lf", &coeffs[i]);
    }

    printf("Enter the initial guess: ");
    scanf("%lf", &initial_guess);

    birgeVieta(coeffs, degree, initial_guess);

    return 0;
}
// output 
// Enter the degree of the polynomial: 3
// Enter the coefficients of the polynomial (highest degree first):
// 1 -6 11 -6
// Enter the initial guess: 2
// Iteration 1: x = 2.000000
// The root is: 2.000000

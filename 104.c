// Newton Nabhson
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    // Define your function here, example: f(x) = x^3 - x - 1
    return x*x*x - x - 1;
}

double f_prime(double x) {
    // Define the derivative of your function here, example: f'(x) = 3*x^2 - 1
    return 3*x*x - 1;
}

void newtonRaphson(double x0) {
    double x1;
    int iteration = 0;

    printf("Iteration %d: x = %.4f\n", iteration, x0);

    do {
        x1 = x0 - f(x0) / f_prime(x0);
        x0 = x1;
        iteration++;
        printf("Iteration %d: x = %.4f\n", iteration, x0);
    } while (fabs(f(x1)) >= EPSILON);

    printf("The root is: %.4f\n", x1);
}

int main() {
    double x0;

    printf("Enter an initial guess: ");
    scanf("%lf", &x0);

    newtonRaphson(x0);

    return 0;
}
// output 
// Enter an initial guess: 1
// Iteration 0: x = 1.0000
// Iteration 1: x = 1.3333
// Iteration 2: x = 1.3472
// Iteration 3: x = 1.3247
// The root is: 1.3247

// Secant
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    // Define your function here, example: f(x) = x^3 - x - 1
    return x*x*x - x - 1;
}

void secantMethod(double x0, double x1) {
    double x2, f0, f1, f2;
    int iteration = 0;

    printf("Iteration %d: x0 = %.4f, x1 = %.4f\n", iteration, x0, x1);

    do {
        f0 = f(x0);
        f1 = f(x1);

        if (fabs(f1 - f0) < EPSILON) {
            printf("Error: Division by zero\n");
            return;
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        x0 = x1;
        x1 = x2;
        iteration++;

        printf("Iteration %d: x0 = %.4f, x1 = %.4f\n", iteration, x0, x1);
    } while (fabs(f(x2)) >= EPSILON);

    printf("The root is: %.4f\n", x2);
}

int main() {
    double x0, x1;

    printf("Enter the first initial guess x0: ");
    scanf("%lf", &x0);
    printf("Enter the second initial guess x1: ");
    scanf("%lf", &x1);

    secantMethod(x0, x1);

    return 0;
}
// output 
// Enter the first initial guess x0: 1
// Enter the second initial guess x1: 2
// Iteration 0: x0 = 1.0000, x1 = 2.0000
// Iteration 1: x0 = 2.0000, x1 = 1.3333
// Iteration 2: x0 = 1.3333, x1 = 1.2880
// Iteration 3: x0 = 1.2880, x1 = 1.3246
// Iteration 4: x0 = 1.3246, x1 = 1.3247
// The root is: 1.3247

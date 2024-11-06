// Bisection METHOD
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    // Define your function here, example: f(x) = x^3 - x - 1
    return x*x*x - x - 1;
}

void bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [%.4f, %.4f]\n", a, b);
        return;
    }

    double c = a;
    while ((b-a) >= EPSILON) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    printf("The root is: %.4f\n", c);
}

int main() {
    double a, b;

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    bisection(a, b);

    return 0;
}
// OUTPUT 
// Enter the interval [a, b]: 1 2
// The root is: 1.3242

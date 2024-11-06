// reguli falsi 
#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    // Define your function here, example: f(x) = x^3 - x - 1
    return x*x*x - x - 1;
}

void regulaFalsi(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [%.4f, %.4f]\n", a, b);
        return;
    }

    double c;
    for (int i = 0; i < 100; i++) {  // Limit iterations to prevent infinite loops
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (fabs(f(c)) < EPSILON) {
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

    regulaFalsi(a, b);

    return 0;
}
// output 
// Enter the interval [a, b]: 1 2
// The root is: 1.3247

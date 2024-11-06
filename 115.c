// Simpson 1/3 rule
#include <stdio.h>

float f(float x) {
    // Define your function here, example: f(x) = x^2
    return x * x;
}

float simpsonsRule(float a, float b, int n) {
    if (n % 2 != 0) {
        printf("Number of intervals must be even.\n");
        return 0;
    }

    float h = (b - a) / n;
    float sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    return (h / 3) * sum;
}

int main() {
    float a, b;
    int n;

    printf("Enter the lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%f", &b);
    printf("Enter the number of sub-intervals (must be even): ");
    scanf("%d", &n);

    float result = simpsonsRule(a, b, n);
    printf("The approximate value of the integral is: %.6f\n", result);

    return 0;
}
// output 
// Enter the lower limit of integration: 0
// Enter the upper limit of integration: 1
// Enter the number of sub-intervals (must be even): 100
// The approximate value of the integral is: 0.333333

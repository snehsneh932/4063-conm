// Trapozoial Rule 
#include <stdio.h>

float f(float x) {
    // Define your function here, example: f(x) = x^2
    return x * x;
}

float trapezoidal(float a, float b, int n) {
    float h = (b - a) / n;
    float sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    return h * sum;
}

int main() {
    float a, b;
    int n;

    printf("Enter the lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%f", &b);
    printf("Enter the number of sub-intervals: ");
    scanf("%d", &n);

    float result = trapezoidal(a, b, n);
    printf("The approximate value of the integral is: %.6f\n", result);

    return 0;
}
// output 
// Enter the lower limit of integration: 0
// Enter the upper limit of integration: 1
// Enter the number of sub-intervals: 100
// The approximate value of the integral is: 0.333333

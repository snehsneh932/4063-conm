// Simpson 3/8 rule
#include <stdio.h>

float f(float x) {
    // Define your function here, example: f(x) = x * x
    return x * x;
}

float simpsons38Rule(float a, float b, int n) {
    if (n % 3 != 0) {
        printf("Number of intervals must be a multiple of 3.\n");
        return 0;
    }

    float h = (b - a) / n;
    float sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }

    return (3 * h / 8) * sum;
}

int main() {
    float a, b;
    int n;

    printf("Enter the lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%f", &b);
    printf("Enter the number of sub-intervals (must be a multiple of 3): ");
    scanf("%d", &n);

    float result = simpsons38Rule(a, b, n);
    if (result != 0) {
        printf("The approximate value of the integral is: %.6f\n", result);
    }

    return 0;
}
// output 
// Enter the lower limit of integration: 0
// Enter the upper limit of integration: 1
// Enter the number of sub-intervals (must be a multiple of 3): 3
// The approximate value of the integral is: 0.333333

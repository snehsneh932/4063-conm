// Lagrange inverse
#include <stdio.h>

void lagrangeInverseInterpolation(float x[], float y[], int n, float value) {
    float result = 0.0;

    for (int i = 0; i < n; i++) {
        float term = x[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (value - y[j]) / (y[i] - y[j]);
            }
        }
        result += term;
    }

    printf("The inverse interpolated value at %.2f is %.2f\n", value, result);
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    float value;
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    lagrangeInverseInterpolation(x, y, n, value);

    return 0;
}
// output 
// Enter the number of data points: 4
// Enter the x and y values:
// x[0] = 1
// y[0] = 1
// x[1] = 2
// y[1] = 4
// x[2] = 3
// y[2] = 9
// x[3] = 4
// y[3] = 16
// Enter the value to interpolate: 6.25
// The inverse interpolated value at 6.25 is 2.50

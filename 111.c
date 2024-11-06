// Newton forward

#include <stdio.h>

#define MAX 10

void newtonForward(float x[], float y[][MAX], int n, float value) {
    float sum = y[0][0];
    float term;
    float h = x[1] - x[0];
    float u = (value - x[0]) / h;

    for (int i = 1; i < n; i++) {
        term = y[0][i];
        for (int j = 0; j < i; j++) {
            term = term * (u - j) / (j + 1);
        }
        sum = sum + term;
    }

    printf("The interpolated value at %.2f is %.2f\n", value, sum);
}

void calculateDifferences(float y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}

int main() {
    int n;
    float value;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][MAX];

    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    calculateDifferences(y, n);

    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    newtonForward(x, y, n, value);

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
// Enter the value to interpolate: 2.5
// The interpolated value at 2.50 is 6.25

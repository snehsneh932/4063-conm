// newton divided Difference Interpolation
#include <stdio.h>

#define MAX 10

void newtonDividedDifference(float x[], float y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
        }
    }
}

float applyFormula(float value, float x[], float y[][MAX], int n) {
    float sum = y[0][0];
    float product;

    for (int i = 1; i < n; i++) {
        product = 1;
        for (int j = 0; j < i; j++) {
            product *= (value - x[j]);
        }
        sum += y[0][i] * product;
    }
    return sum;
}

void display(float x[], float y[][MAX], int n) {
    printf("\nThe divided difference table is:\n");
    for (int i = 0; i < n; i++) {
        printf("%f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
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

    newtonDividedDifference(x, y, n);
    display(x, y, n);

    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    float result = applyFormula(value, x, y, n);
    printf("\nThe interpolated value at %.2f is %.2f\n", value, result);

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

// The divided difference table is:
// 1.000000    1.000000    3.000000    1.000000    0.000000
// 2.000000    4.000000    5.000000    0.000000
// 3.000000    9.000000    7.000000
// 4.000000    16.000000

// Enter the value to interpolate: 2.5

// The interpolated value at 2.50 is 6.25

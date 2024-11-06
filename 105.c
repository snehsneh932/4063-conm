// Gauss elmination
#include <stdio.h>
#include <math.h>

#define SIZE 10

void gaussElimination(float a[SIZE][SIZE], int n) {
    int i, j, k;
    float ratio;

    // Performing Gaussian elimination
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (a[i][i] == 0.0) {
                printf("Mathematical Error!");
                return;
            }
            ratio = a[j][i]/a[i][i];
            for (k = 0; k < n+1; k++) {
                a[j][k] = a[j][k] - ratio*a[i][k];
            }
        }
    }

    // Back Substitution
    float x[SIZE];
    x[n-1] = a[n-1][n]/a[n-1][n-1];

    for (i = n-2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i+1; j < n; j++) {
            x[i] = x[i] - a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }

    // Displaying the result
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }
}

int main() {
    float a[SIZE][SIZE];
    int i, j, n;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n+1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussElimination(a, n);

    return 0;
}
// output
// Enter the number of variables: 3
// Enter the coefficients of the augmented matrix:
// 2 1 -1 -8
// -3 -1 2 -11
// -2 1 2 -3

// The solution is:
// x[0] = 2.00
// x[1] = 3.00
// x[2] = -1.00
 
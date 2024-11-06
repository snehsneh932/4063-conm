// Gauss jorden 
#include <stdio.h>

#define SIZE 10

void gaussJordan(float a[SIZE][SIZE], int n) {
    int i, j, k;
    float ratio;

    // Applying Gauss Jordan Elimination
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Making principal diagonal elements to 1
    for (i = 0; i < n; i++) {
        for (j = n; j >= 0; j--) {
            a[i][j] = a[i][j] / a[i][i];
        }
    }

    // Displaying the result
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, a[i][n]);
    }
}

int main() {
    float a[SIZE][SIZE];
    int i, j, n;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussJordan(a, n);

    return 0;
}
// output 
// Enter the number of variables: 3
// Enter the coefficients of the augmented matrix:
// 2 1 -1 8
// -3 -1 2 -11
// -2 1 2 -3

// The solution is:
// x[0] = 2.00
// x[1] = -3.00
// x[2] = -1.00

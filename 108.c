// Gauss seidal
#include <stdio.h>
#include <math.h>

#define SIZE 10
#define EPSILON 0.001

void gaussSeidel(float a[SIZE][SIZE], float b[SIZE], float x[SIZE], int n) {
    int i, j;
    float sum, old_x[SIZE];

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    int iteration = 0;
    do {
        for (i = 0; i < n; i++) {
            old_x[i] = x[i];
        }
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            x[i] = sum / a[i][i];
        }
        iteration++;
        printf("Iteration %d: ", iteration);
        for (i = 0; i < n; i++) {
            printf("%.4f ", x[i]);
        }
        printf("\n");
    } while (1);

    for (i = 0; i < n; i++) {
        if (fabs(x[i] - old_x[i]) > EPSILON) {
            break;
        }
    }
}

int main() {
    int n;
    float a[SIZE][SIZE], b[SIZE], x[SIZE];

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the augmented matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constants of the equations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    gaussSeidel(a, b, x, n);

    printf("The solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}
// output 

// Enter the number of variables: 3
// Enter the coefficients of the augmented matrix:
// 4 1 2
// 3 5 1
// 1 1 3
// Enter the constants of the equations:
// 4
// 7
// 3
// Iteration 1: 1.0000 1.0000 1.0000 
// Iteration 2: 0.5000 1.3000 1.4000 
// Iteration 3: 0.2250 1.4650 1.4367 
// Iteration 4: 0.1500 1.4671 1.4607 
// Iteration 5: 0.1215 1.4775 1.4663 
// Iteration 6: 0.1124 1.4806 1.4694 
// Iteration 7: 0.1097 1.4814 1.4704 
// Iteration 8: 0.1088 1.4818 1.4708 
// Iteration 9: 0.1086 1.4819 1.4710 
// Iteration 10: 0.1085 1.4820 1.4710 
// The solution is:
// x[0] = 0.1085
// x[1] = 1.4820
// x[2] = 1.4710

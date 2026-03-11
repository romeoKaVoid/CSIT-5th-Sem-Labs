#include <stdio.h>
// multiply two matrices
void multiply(float A[10][10], float B[10][10], float result[10][10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = 0;
            for(int k = 0; k < n; k++) {
                result[i][j] = result[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }
}

// multiply vector and matrix
void mulVect(float X[10], float P[10][10], float result[10], int n) {
    for(int j = 0; j < n; j++) {
        result[j] = 0;
        for(int i = 0; i < n; i++) {
            result[j] = result[j] + (X[i] * P[i][j]);
        }
    }
}
int main() {
    int n, steps;
    float P[10][10];
    float temp[10][10];
    float X0[10], Xn[10];
    printf("Enter number of states: ");
    scanf("%d", &n);
    printf("Enter transition probability matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%f", &P[i][j]);
        }
    }
    printf("Enter initial probability vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%f", &X0[i]);
    }
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = P[i][j];
        }
    }
    for(int s = 1; s < steps; s++) {
        float result[10][10];
        multiply(temp, P, result, n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                temp[i][j] = result[i][j];
        }
    }
    mulVect(X0, temp, Xn, n);
    printf("\nState Probability after %d steps:\n", steps);
    for(int i = 0; i < n; i++) {
        printf("State %d: %.3f\n", i, Xn[i]);
    }
    printf("\n  -By Krishna Aryal");
    return 0;
}
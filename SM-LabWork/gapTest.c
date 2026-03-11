#include <stdio.h>
#include <math.h>

#define MAX 200
#define MAXGAP 20

int main() {

    float R[MAX];
    int N;
    float a, b;
    int gap = 0;
    int O[MAXGAP] = {0};
    float E[MAXGAP];
    float chi_square = 0;
    float p, q;
    int total_gaps = 0;

    printf("Enter total number of random numbers (N): ");
    scanf("%d", &N);

    printf("Enter random numbers (0 to 1):\n");
    for(int i = 0; i < N; i++) {
        scanf("%f", &R[i]);
    }

    printf("Enter interval [a b]: ");
    scanf("%f %f", &a, &b);

    p = b - a;
    q = 1 - p;

    // Count gaps
    for(int i = 0; i < N; i++) {

        if(R[i] >= a && R[i] <= b) {
            if(gap < MAXGAP)
                O[gap]++;
            gap = 0;
            total_gaps++;
        }
        else {
            gap++;
        }
    }

    printf("\nObserved Gap Frequencies:\n");
    for(int i = 0; i < MAXGAP; i++) {
        if(O[i] > 0)
            printf("Gap %d : %d\n", i, O[i]);
    }

    // Expected frequencies
    for(int r = 0; r < MAXGAP; r++) {
        E[r] = total_gaps * pow(q, r) * p;
        if(E[r] > 0)
            chi_square += pow(O[r] - E[r], 2) / E[r];
    }

    printf("\nChi-Square value = %f\n", chi_square);
    float critical;
    critical = 1.36/sqrt(N);
    if (chi_square <= critical)
    {
        printf("\nWe accept Null Hypothesis(means Uniform)");
    }
    else{
        printf("\nWe reject Null Hypothesis(means not Uniform)");
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
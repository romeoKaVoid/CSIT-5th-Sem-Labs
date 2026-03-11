#include <stdio.h>
#include <math.h>
#define MAX 200
int main() {
    float R[MAX];
    int N, k, O[50] = {0};   
    float E, chisq = 0.0;
    float interval;

    printf("Enter number of Random Numbers(N): ");
    scanf("%d",&N);
    printf("Enter Random Numbers(between 0 and 1):\n");
    for(int i = 0; i < N; i++) {
        scanf("%f",&R[i]);
    }
    printf("Enter number of intervals (k): ");
    scanf("%d",&k);
    interval = 1.0 / k;

    for(int i = 0; i < N; i++) {
        int index = R[i] / interval;

        if(index == k){
            index = k - 1;
        }
        O[index]++;
    }
    E = (float)N / k;
    for(int i = 0; i < k; i++) {
        chisq = chisq + (pow((O[i] - E), 2) / E);
    }
    printf("\nObserved Frequencies:\n");
    for(int i = 0; i < k; i++) {
        printf("Class %d- %d\n", i+1, O[i]);
    }
    printf("\nChi-Square value = %.4f\n", chisq);
    printf("Degrees of Freedom = %d\n", k-1);

    printf("\nEnter given critical value from table for %d deg.of freedom: ");
    float chi_critical;
    scanf("%f",&chi_critical);
    if (chisq <= chi_critical)
    {
        printf("\nWe accept Null Hypothesis(means Uniform)");
    }
    else{
        printf("\nWe reject Null Hypothesis(means not Uniform)");
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
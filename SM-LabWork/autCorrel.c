#include<stdio.h>
#include<math.h>
int main()
{
    int n, i, m, M;
    float R[100], rho = 0.0, var, Z0;
    printf("Enter the number of Random Numbers(N): ");
    scanf("%d",&n); 
    printf("Enter the Random Numbers(between 0 and 1): ");
    for (int k = 0; k < n; k++)
    {
        scanf("%f",&R[k]);
    }
    printf("Enter starting index(i): ");
    scanf("%d",&i);
    printf("Enter the gap(m): ");
    scanf("%d",&m);

    M = ((n-i)/m)-1;
    if (M<0)
    {
        printf("Not enough numbers for given i and m!!\n");
        return 0;
    }
    for (int k = 0; k <=M; k++)
    {
        rho = rho + R[i+k*m] * R[i+(k+1)*m];
    }
    rho = (rho/(M+1)) - 0.25;
    var = (sqrt(13*M + 7))/(12*(M+1));
    Z0 = rho/var;

    printf("\nM = %d", M);
    printf("\nrho = %.4f", rho);
    printf("\nvar = %.4f", var);
    printf("\nZ0 = %.4f", Z0);

    if (fabs(Z0)<1.96)
    {
        printf("\nWe accept Null Hypothesis!!(means Independent)");
    }
    else{
        printf("\nWe reject Null Hypothesis!!(means Not Independent)");
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
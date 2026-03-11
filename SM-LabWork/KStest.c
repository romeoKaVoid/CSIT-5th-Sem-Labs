#include<stdio.h>
#include<math.h>
void sort(float a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    float R[50], Dplus = 0, Dminus = 0, D;
    float Dcrit;
    printf("Enter number of random numbers: ");
    scanf("%d",&n);
    printf("Enter the Random Numbers(between 0 and 1): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&R[i]);
    }
    sort(R,n);
    for (int i = 0; i < n; i++)
    {
        float Dp = ((float)(i+1)/n) - R[i];
        float Dm = R[i]-((float)i/n);

        if (Dp>Dplus)
        {
            Dplus = Dp;
        }
        if (Dm>Dminus)
        {
            Dminus = Dm;
        }
    }
    D = (Dplus>Dminus) ? Dplus:Dminus;
    //for alpha = 0.05
    Dcrit = 1.36 / sqrt(n);

    printf("\nD+ = %.3f",Dplus);
    printf("\nD- = %.3f",Dminus);
    printf("\nD = %.3f",D);
    printf("\nCritical Value = %.3f",Dcrit);

    if (D < Dcrit)
    {
        printf("\nWe accept Null Hypothesis(means Uniform Distribution)!!");
    }
    else{
        printf("\nWe reject Null Hypothesis!!");
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
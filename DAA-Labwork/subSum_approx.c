#include<stdio.h>
int S, s[10], x[10], n;
void ApproxSubset()
{
    int sum = 0;
    for (int i = 1; i <= n; i++){
        x[i] = 0;
    }
    // traverse from largest to smallest
    for (int i = n; i >= 1; i--)
    {
        if (sum + s[i] <= S)
        {
            x[i] = 1;
            sum = sum + s[i];
        }
    }
    printf("\nApproximate Subset: ");
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1){
            printf("\t%d", s[i]);
        }
    }
    printf("\nApproximate Sum = %d", sum);
}
int main()
{
    int sum = 0;
    printf("Enter size of set: ");
    scanf("%d", &n);
    printf("Enter the set in increasing order: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        sum = sum + s[i];
    }
    printf("Enter the target Sum: ");
    scanf("%d", &S);
    if (sum < S)
    {
        printf("\nNo Possible Subset!!");
    }
    else
    {
        ApproxSubset();
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
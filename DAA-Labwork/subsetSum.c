#include<stdio.h>
int S,s[10],x[10],n;
void SubSum(int m, int k, int r);
int main()
{
    int sum=0;
    printf("Enter size of set: ");
    scanf("%d",&n);
    printf("\nEnter the set in increasing order: ");
    for (int i = 1; i <=n; i++)
    {
        scanf("%d",&s[i]);
        sum = sum + s[i];
    }
    printf("Enter the target Sum: ");
    scanf("%d",&S);
    if (sum<S || s[1]>S)
    {
        printf("\nNo Possible Subset!!");
    }
    else{
        SubSum(0,1,sum);
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
void SubSum(int m, int k , int r){
    x[k] = 1;
    if (m + s[k] == S)
    {
        printf("\nSubset: ");
        for (int i = 1; i <=k; i++)
        {
            if (x[i]==1)
                printf("\t%d",s[i]);
        }
    }
    else{
        if (m + s[k] + s[k+1] <=S)
        {
            SubSum(m+s[k], k+1, r-s[k]);
        }
        if ((m+r-s[k] >= S) && (m+s[k+1] <=S))
        {
            x[k] = 0;
            SubSum(m, k+1, r-s[k]);
        }
    }
}
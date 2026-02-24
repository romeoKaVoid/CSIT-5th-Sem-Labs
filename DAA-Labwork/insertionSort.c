#include<stdio.h>
int main()
{
    int A[50], n, temp,j,count=0;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i = 1; i < n; i++)
    {
        temp = A[i];
        for ( j = i-1; j >= 0 && A[j]>=temp; j--)
        {
            A[j+1] = A[j];
            count++;
        }
        A[j+1] = temp;
    }
    printf("\nInsertion Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
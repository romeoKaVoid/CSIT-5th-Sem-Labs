#include<stdio.h>
int main()
{
    int A[50], n, temp,count=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            count++;
            if (A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    printf("\nBubble Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ",A[i]);
    }
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
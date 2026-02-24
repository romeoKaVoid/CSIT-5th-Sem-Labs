#include <stdio.h>
int count = 0;
void MinMax(int A[], int l, int r, int *min, int *max);
int main()
{
    int A[50], n, min, max, l, r;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    l = 0;
    r = n-1;

    MinMax(A,l,r,&min,&max);

    printf("\nLargest element in array = %d", max);
    printf("\nSmallest element in array = %d", min);
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
void MinMax(int A[], int l, int r, int *min, int *max)
{
    int min1, max1, m;
    if (l == r)
    {
        *min = *max = A[l];
    }
    else if (r == l + 1)
    {
        count++;
        if (A[l] > A[r])
        {
            *min = A[r];
            *max = A[l];
        }
        else
        {
            *min = A[l];
            *max = A[r];
        }
    }
    else
    {
        m = (l + r) / 2;
        MinMax(A,l,m,min,max);
        MinMax(A,m+1,r,&min1,&max1);

        count++;
        if (max1>*max)
        {
            *max = max1;
        }
        count++;
        if (min1<*min)
        {
            *min = min1;
        }
    }
}
#include <stdio.h>
int count = 0;
int partition(int A[], int l, int r);
void swap(int *a, int *b);
void quickSort(int A[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(A, l, r);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, r);
    }
}
int main()
{
    int A[50], l, r, n;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    l = 0;
    r = n - 1;
    quickSort(A, l, r);
    printf("\nSorted array using Quick Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", A[i]);
    }
    printf("\nEmpirical Analysis: %d \n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
int partition(int A[], int l, int r)
{
    int x, y, p;
    x = l, y = r, p = A[l];
    while (x < y)
    {
        while ( x<=r && A[x] <= p)
        {
            count++;
            x++;
        }
        while (A[y] > p)
        {
            count++;
            y--;
        }
        if (x < y)
        {
            swap(&A[x], &A[y]);
        }
    }
    swap(&A[l], &A[y]);
    return y;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
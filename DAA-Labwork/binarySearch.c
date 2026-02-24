#include <stdio.h>
int count = 0;
void BinSearch(int A[], int l, int r, int key)
{
    count++;
    int m;
    if (l > r)
    {
        printf("Key not Found!!\n");
    }
    else
    {
        m = (l + r) / 2;
        if (A[m] == key)
        {
            printf("Key found at %dth place", m + 1);
        }
        else if (key < A[m])
        {
            return BinSearch(A, l, m - 1, key);
        }
        else
        {
            return BinSearch(A, m + 1, r, key);
        }
    }
}
int main()
{
    int A[50], n, key, l, r;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    l = 0;
    r = n - 1;
    printf("\nEnter the key to Search: ");
    scanf("%d", &key);
    BinSearch(A, l, r, key);
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
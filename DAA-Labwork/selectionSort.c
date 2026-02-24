#include <stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int A[50], n, min, minloc,count=0;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        minloc = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (A[j] < A[minloc])
            {
                minloc = j;
            }
        }
    //    int temp;
    //    temp = A[i];
    //    A[i] = A[minloc];
    //    A[minloc] = temp;
    swap(&A[i],&A[minloc]);
    }
    printf("\nSelection Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}

#include <stdio.h>
int count = 0;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void buildHeap(int A[], int n);
void heapify(int A[], int i, int n);
void HeapSort(int A[], int n)
{
    buildHeap(A, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(&A[i], &A[0]);
        heapify(A, 0, i);
    }
}
int main()
{
    int A[50], n;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    HeapSort(A, n);
    printf("\nSorted array using HeapSort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\nEmpirical Analysis: %d (Steps)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
void buildHeap(int A[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(A, i, n);
    }
}
void heapify(int A[], int i, int n)
{
    int l, r, largest;
    l = 2 * i + 1;
    r = 2 * i + 2;
    largest = i;
    if (l < n)
    {
        count++;
        if (A[l] > A[largest])
            largest = l;
    }

    if (r < n)
    {
        count++;
        if (A[r] > A[largest])
            largest = r;
    }
    if (i != largest)
    {
        swap(&A[i], &A[largest]);
        heapify(A, largest, n);
    }
}
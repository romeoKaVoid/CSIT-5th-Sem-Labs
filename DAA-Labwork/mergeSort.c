#include<stdio.h>
int count =0;
void merge(int A[],int l, int m, int r);
void merge_sort(int A[],int l,int r){
    // count++;
    if (l<r)
    {
        int m;
        m = (l+r)/2;
        merge_sort(A,l,m);
        merge_sort(A,m+1,r);
        merge(A,l,m+1,r);
    }
}
int main()
{
    int A[50],l,r,n;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    l=0;
    r=n-1;
    merge_sort(A,l,r);
    printf("\nSorted Array using Merge Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
void merge(int A[],int l,int m,int r){
    int x,y,k,B[50];
    x=l,y=m,k=l;
    while (x<m&&y<=r)
    {
        count++;
        if (A[x]<A[y])
        {
            B[k] = A[x];
            x++;
            k++;
        }
        else{
            B[k] = A[y];
            y++;
            k++;
        }
    }
    while (x<m)                 
    {
        B[k]=A[x];
        x++;
        k++;
    }
    while (y<=r)
    {
        B[k]=A[y];
        y++;
        k++;
    }
    for (int i = l; i <=r; i++)
    {
        A[i] = B[i];
    }
}
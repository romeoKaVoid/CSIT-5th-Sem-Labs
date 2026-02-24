#include<stdio.h>
int main()
{
    int A[50], n, key, flag, index,count=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter array Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nEnter key to Search: ");
    scanf("%d",&key);
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (A[i]==key)
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Key found at index: %d", index);
    }
    else{
        printf("Key not found!!");
        // count++;
    }
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n  -By Krishna Aryal");
    return 0;
}
#include<stdio.h>
int main()
{
    int n, a= 0, b = 1, c, count=0;
    printf("Enter the no. of Fibonacci series to print: ");
    scanf("%d",&n);
    printf("Fibonacci Series: %d, %d",a,b);
    for (int i = 2; i <n; i++)
    {
        c = a + b;
        printf(", %d",c);
        a = b;
        b = c;
        count++;
    }
    printf("\nEmpirical Analysis: %d (Iterations)\n",count);
    printf("\n\n - By Krishna Aryal");
    return 0;
}
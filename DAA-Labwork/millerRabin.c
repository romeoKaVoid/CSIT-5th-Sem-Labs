#include <stdio.h>

// Function to compute (a^m) % n
int power( int a, int m, int n)
{
    int result = 1;
    a = a % n;
    while (m > 0)
    {
        if (m % 2 == 1)
            result = (result * a) % n;
        a = (a * a) % n;
        m = m / 2;
    }
    return result;
}

int main()
{
    int n, a, m;
    int k = 0,flag=0;

    printf("Enter the number to test(n): ");
    scanf("%d", &n);

    printf("Enter value of a (1 < a < n-1): ");
    scanf("%d", &a);

    // Step 1: find k and m such that n-1 = 2^k * m
    m = n - 1;
    while (m % 2 == 0)
    {
        m = m / 2;
        k++;
    }
    printf("\nWe have: ");
    printf("n - 1 = 2^%d * %d\n", k, m);

    // Step 2: compute b = a^m % n
    int b = power(a, m, n);

    // Step 3: check conditions
    if (b == 1 || b == n - 1)
    {
        flag=1;
    }
    // Step 4: repeat k-1 times
    for (int i = 1; i < k; i++)
    {
        b = (b * b) % n;
        if (b == n - 1)
        {
            flag=1;
        }
    }
    if (flag==1)
    {
        printf("\n%d is probably Prime!!",n);
    }else{
        printf("\n%d is Composite!!\n",n);
    }
    printf("\n  -By Krishna Aryal");
    return 0;
}
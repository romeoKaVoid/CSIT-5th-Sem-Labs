#include<stdio.h>
long int power(long int base, long int exp, long int mod){
    long int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result = (result*base) % mod;
    }
    return result;
}
int pimRoot(int g, int p){
    int visited[1000] = {0};
    for (int i = 1; i <= p-1; i++)
    {
        int val = power(g,i,p);
        if (visited[val] ==1)
        {
            return 0;
        }
        visited[val] =1;
    }
    return 1;
}
int main()
{
    int p;
    printf("Enter a prime number: ");
    scanf("%d",&p);
    printf("\nPrimitive roots of %d are\n",p);
    for (int g = 0; g < p; g++)
    {
        if (pimRoot(g,p))
        {
            printf("%d, ",g);
        }
    }
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
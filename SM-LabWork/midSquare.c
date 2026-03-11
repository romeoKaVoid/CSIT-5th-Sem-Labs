#include<stdio.h>
#include<math.h>
int digCount(int n){
    int count = 0;
    while (n!=0)
    {
        n = n/10;
        count++;
    }
    return count;
}
int main()
{
    int dig, n, seed;
    long int sq, nxt, div;
    printf("Enter the seed: ");
    scanf("%d",&seed);
    dig = digCount(seed);
    printf("Enter how many Random Numbers to generate: ");
    scanf("%d",&n);
    printf("\nGenereated Random Numbers are:\n");
    for (int i = 0; i < n; i++)
    {
        sq = pow(seed,2);
        div = pow(10,(dig/2));
        nxt = (sq/div) % (long)pow(10,dig);
        printf("X%d = %ld\n",i+1,nxt);
        seed = nxt;
        if (seed == 0)
        {
            printf("\nSequence ended(became 0)!!\n");
            break;
        }
    }
    printf("\n  -By Krishna Aryal");
    return 0;
}
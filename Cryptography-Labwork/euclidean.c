#include<stdio.h>
int gcd(int x, int y){
    int r,c;
    while (y!=0)
    {
        int r = x;
        c = x%y;
        x = y;
        y = c;
    }
    return x;
}
int main()
{
    int a,b;
    printf("Enter value of a (integer): ");
    scanf("%d",&a);
    printf("Enter value of b (+ve integer): ");
    scanf("%d",&b);
    printf("\nUsing Euclidean Algorithm:\n");
    printf("GCD(%d, %d) = %d",a,b,gcd(a,b));
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
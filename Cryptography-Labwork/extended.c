#include<stdio.h>
int s,t;
int extended(int a, int b){
    int s0 = 1, s1 = 0, t0 = 0, t1 = 1;
    int q,r;
    while(b!=0){
        q = a/b;
        r = a%b;

        a = b;
        b = r;

        s = s0-q*s1;
        t = t0-q*t1;
        s0 = s1;
        t0 = t1;
        s1 = s;
        t1 = t;
    }
    s = s0;
    t = t0; //for printing
    return a;
}
int main()
{
    int x,y;
    printf("Enter value of a(integer): ");
    scanf("%d",&x);
    printf("Enter value of b(integer): ");
    scanf("%d",&y);
    printf("\nUsing Extended Euclidean Algorithm:\n");
    printf("GCD(%d, %d) = %d",x,y,extended(x,y));
    printf("\n2 integers that satisfy (gcd(a,b) = s*a + t*b) are:\n");
    printf("s = %d\nt = %d",s,t);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
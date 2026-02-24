#include<stdio.h>
int main()
{
    int a,b,x,y,r,count=0;
    printf("Enter 2 +ve integers to find GCD: ");
    scanf("%d%d",&a,&b);
    x=a;
    y=b;
    if (a==0){
        printf("GCD(%d, %d) = %d",x,y,b);
        count++;
    }
    else if(b==0){
        printf("GCD(%d, %d) = %d",x,y,a);
        count++;
    }
    else{
        while(b!=0){
            r = a%b;
            a = b;
            b = r;
            count++;
        }
        printf("GCD(%d, %d) = %d",x,y,a);
    }
printf("\nEmpirical Analysis: %d (Iterations)\n",count);
printf("\n  -By Krishna Aryal");
return 0;
}
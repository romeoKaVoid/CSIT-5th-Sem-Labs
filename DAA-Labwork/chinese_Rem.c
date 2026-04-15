#include<stdio.h>
int a[10],m[10];
int chinese(int);
int main()
{
    int n;
    printf("Enter no. of simultaneous congruencies: ");
    scanf("%d",&n);
    printf("Enter values of a & mod:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&a[i],&m[i]);
    }
    printf("\nSimultaneous Congruencies as per your data are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x = %d (mod %d)\n",a[i],m[i]);
    }
    int X= chinese(n);
    printf("\nThe required value of X = %d",X);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
int chinese(int n){
    int Y= 1, M[10],inv[50];
    int result=0,x[10];
    for (int i = 0; i < n; i++)
    {
        Y = Y*m[i];
    }
    for (int i = 0; i < n; i++)
    {
        M[i] = Y/m[i];    
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if ((M[i]*j)%m[i] == 1)
            {
                inv[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        result = result + (M[i]*inv[i]*a[i]);
    }
    result = result % Y;
    return result;
}
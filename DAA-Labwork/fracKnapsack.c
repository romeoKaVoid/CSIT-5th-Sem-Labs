#include <stdio.h>
void swap(float *a,float *b){
    float temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
void FracKnapsack(float profit[],float weight[],float capacity, int n)
{
    float X[50],ratio[50];
    float totProfit = 0;

    for ( int i = 0; i < n; i++)
    {
        ratio[i] = profit[i]/weight[i];
        X[i] = 0.0;
    }

    //Using Bubble Sort to Sort
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (ratio[j] < ratio[j+1])
            {
                //Swapping ratio
                swap(&ratio[j],&ratio[j+1]);
    
                //Swapping Profit
                swap(&profit[j],&profit[j+1]);
    
                //Swapping Weights
                swap(&weight[j],&weight[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            X[i] = 1.0;
            capacity = capacity - weight[i];
            totProfit = totProfit+profit[i];
        }
        else{
            X[i] = capacity/weight[i];
            totProfit = totProfit + (X[i]*profit[i]);
            break;
        }
    }

    printf("\nSelected Fractions:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: %.2f\n",i+1,X[i]);
    }
    printf("\nMaximum Profit: %.2f",totProfit);
}
int main()
{
    float profit[50], W[50], capacity;
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter profit of each items: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&profit[i]);
    }
    
    printf("Enter weights of each items: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&W[i]);
    }
    
    printf("Enter the capacity of kanpsack: ");
    scanf("%f",&capacity);

    FracKnapsack(profit,W,capacity,n);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}

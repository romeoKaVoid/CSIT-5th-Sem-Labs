#include <stdio.h>
#define MAX 100
int max(int a, int b)
{
    return (a>b) ? a:b;
}
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[MAX][MAX];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0){
                K[i][w] = 0;
            }
            else if (wt[i-1] <= w){
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]],
                              K[i-1][w]);
            }
            else{
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][W];
}
int main()
{
    int n, W;
    int wt[MAX], val[MAX];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &wt[i]);
    }
    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &val[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    int maxProfit = knapsack(W, wt, val, n);
    printf("\nMaximum Profit = %d", maxProfit);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
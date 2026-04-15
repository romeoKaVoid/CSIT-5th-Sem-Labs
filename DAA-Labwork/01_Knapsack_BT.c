#include <stdio.h>

int n, W;
int w[20], p[20], x[20], bestX[20];
int maxProfit = 0;

void Knapsack(int i, int profit, int weight)
{
    if (weight <= W && profit > maxProfit){
        maxProfit = profit;
        // For Item Select
        for (int k = 1; k <= n; k++)
            bestX[k] = x[k];
    }
    if (i == n){
        return;   
    }
    // Include item
    x[i+1] = 1;
    if (weight + w[i+1] <= W){
        Knapsack(i+1, profit + p[i+1], weight + w[i+1]);
    }
    // Exclude item
    x[i+1] = 0;
    Knapsack(i+1, profit, weight);
}

int main()
{
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights: ");
    for (int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    printf("Enter profits: ");
    for (int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
    }
    printf("Enter capacity: ");
    scanf("%d", &W);

    Knapsack(0, 0, 0);

    printf("\nMaximum Profit = %d", maxProfit);
    printf("\nSelected items:\n");
    for (int i = 1; i <= n; i++)
    {
        if (bestX[i] == 1)
            printf("Item %d (W=%d, P=%d)\n", i, w[i], p[i]);
    }
    printf("\n  -By Krishna Aryal");
    return 0;
}
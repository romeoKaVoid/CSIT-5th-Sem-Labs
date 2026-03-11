#include <stdio.h>
#define MAX 50
#define INF 99999
void FWarshall(int g[MAX][MAX], int V)
{
    int D[MAX][MAX];
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            D[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (D[i][j] == INF){
                printf("INF ");
            }
            else{
                printf("%3d ", D[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int V;
    int graph[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter adjacency matrix(use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    FWarshall(graph, V);
    printf("\n  -By Krishna Aryal");
    return 0;
}
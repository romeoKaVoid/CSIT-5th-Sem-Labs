#include <stdio.h>
#define MAX 20

int main()
{
    int n, m;
    int u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int edges[MAX][2];
    int visited[MAX] = {0};
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    printf("\nApproximate Vertex Cover:\n");
    for (int i = 0; i < m; i++)
    {
        u = edges[i][0];
        v = edges[i][1];

        // If both vertices are not yet selected
        if (visited[u] == 0 && visited[v] == 0)
        {
            visited[u] = 1;
            visited[v] = 1;

            printf("%d %d ", u, v);
        }
    }
    printf("\n");
    printf("\n\n  -By Krishna Aryal");
    return 0;
}
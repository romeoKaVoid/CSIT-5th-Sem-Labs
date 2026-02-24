#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2)
{
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;
    return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int V)
{
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] != component)
        parent[component] = findParent(parent, parent[component]);

    return parent[component];
}

void unionSet(int u, int v, int parent[], int rank[])
{
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int V, int E, int edge[E][3])
{
    qsort(edge, E, sizeof(edge[0]), comparator);

    int parent[V];
    int rank[V];

    makeSet(parent, rank, V);

    int minCost = 0;

    printf("\nEdges in MST:\n");

    for (int i = 0; i < E; i++) {

        int u = findParent(parent, edge[i][0]);
        int v = findParent(parent, edge[i][1]);
        int wt = edge[i][2];

        if (u != v) {
            unionSet(u, v, parent, rank);
            minCost += wt;
            printf("%d -- %d == %d\n", edge[i][0], edge[i][1], wt);
        }
    }

    printf("\nMinimum Cost of MST: %d\n", minCost);
}

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edge[E][3];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    kruskalAlgo(V, E, edge);

    printf("\n\n  -By Krishna Aryal");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100   
int parent[MAX], rank[MAX];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]); 
    return parent[i];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void kruskalMST(int cost[MAX][MAX], int n) {
    int edges[MAX * MAX][3];  
    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (cost[i][j] != 0) {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = cost[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp0 = edges[j][0], temp1 = edges[j][1], temp2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp0;
                edges[j + 1][1] = temp1;
                edges[j + 1][2] = temp2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstEdges = 0, totalCost = 0;
    
    printf("Edges in the Minimum Spanning Tree:\n");
    
    for (int i = 0; i < edgeCount && mstEdges < n - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (find(u) != find(v)) { 
            printf("%d -- %d == %d\n", u, v, weight);
            unionSet(u, v);
            totalCost += weight;
            mstEdges++;
        }
    }

    printf("Total cost of MST: %d\n", totalCost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);  
        }
        printf("\n");
    }

    kruskalMST(cost, n);
    return 0;
}

#include <stdio.h>

#define MAX 100
int n;
int graph[MAX][MAX];     
int inDegree[MAX];     
int queue[MAX];        
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < vertices; j++) {
            if (graph[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    int topOrder[MAX];

    while (!isEmpty()) {
        int u = dequeue();
        topOrder[count++] = u;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] == 1) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    if (count != vertices) {
        printf("There exists a cycle in the graph. Topological sort not possible.\n");
    } else {
        printf("Topological Ordering: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topOrder[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);  
        }
        printf("\n");
    }

    topologicalSort(n);

    return 0;
}

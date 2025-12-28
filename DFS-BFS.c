#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void DFS(int adj[MAX][MAX], int visited[], int n, int source) {
    int i;
    visited[source] = 1;
    printf("%d ", source);

    for (i = 0; i < n; i++) {
        if (adj[source][i] == 1 && !visited[i]) {
            DFS(adj, visited, n, i);
        }
    }
}

void BFS(int adj[MAX][MAX], int n, int source) {
    int visited[MAX] = {0};
    int i, current;

    visited[source] = 1;
    enqueue(source);

    printf("BFS Traversal: ");
    while ((current = dequeue()) != -1) {
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 5; 
    int i;
    int visitedDFS[MAX] = {0};

    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 0}, 
        {0, 1, 0, 0, 0} 
    };

    printf("DFS Traversal: ");
    DFS(adj, visitedDFS, n, 0);
    printf("\n");

    BFS(adj, n, 0);

    return 0;
}

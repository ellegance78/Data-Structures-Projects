#include <stdio.h>

#define MAX 10

void findCluster(int graph[MAX][MAX], int visited[], int n, int node) {
    int j;
    visited[node] = 1;
    printf("%d ", node);

    for (j = 0; j < n; j++) {
        
        if (graph[node][j] == 1 && !visited[j]) {
            findCluster(graph, visited, n, j);
        }
    }
}

int main() {
    int i, j;
    int n = 6;
    int clusterCount = 0;
    int visited[MAX] = {0}; 

    int graph[MAX][MAX] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0}, 
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}  
    };

    printf("Clusters found in the graph:\n");

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            findCluster(graph, visited, n, i);
            printf("}\n");
        }
    }
    printf("\nTotal number of clusters: %d\n", clusterCount);

    return 0;
}

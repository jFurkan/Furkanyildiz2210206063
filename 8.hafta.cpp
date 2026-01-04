#include <stdio.h>
#include <stdbool.h>

#define N 7 


void DFS(int graph[N][N], int node, bool visited[]) {

    visited[node] = true;
    printf("%d ", node);


    for (int i = 0; i < N; i++) {

        if (graph[node][i] == 1 && !visited[i]) {

        }
    }
}

void findClusters(int graph[N][N]) {

    int clusterCount = 0;

    printf("Graph icindeki Kumeler (Clusters):\n");
    printf("----------------------------------\n");


    for (int i = 0; i < N; i++) {

        if (visited[i] == false) {
            clusterCount++;
            printf("Kume %d: { ", clusterCount);
            

            DFS(graph, i, visited);
            
            printf("}\n");
        }
    }
    printf("----------------------------------\n");
    printf("Toplam Kume Sayisi: %d\n", clusterCount);
}

int main() {

    
    int graph[N][N] = {
        // 0  1  2  3  4  5  6
        {0, 1, 1, 0, 0, 0, 0}, 
        {1, 0, 1, 0, 0, 0, 0}, 
        {1, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0}  

    findClusters(graph);

    return 0;
}

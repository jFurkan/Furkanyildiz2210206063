#include <stdio.h>
#include <stdbool.h>

#define N 6 


int kuyruk[N];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == N - 1) return; // Kuyruk dolu
    if (front == -1) front = 0;
    rear++;
    kuyruk[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) return -1; 
    int item = kuyruk[front];
    front++;
    if (front > rear) front = rear = -1; 
    return item;
}

bool isQueueEmpty() {
    return front == -1;
}

void DFS(int graph[N][N], int startNode, bool visited[]) {
 
    visited[startNode] = true;
    printf("%d ", startNode);

  
    for (int i = 0; i < N; i++) {
     
        if (graph[startNode][i] == 1 && !visited[i]) {
            DFS(graph, i, visited); 
        }
    }
}


void BFS(int graph[N][N], int startNode) {

    bool visited[N] = {false};


    enqueue(startNode);
    visited[startNode] = true;

    while (!isQueueEmpty()) {

        int currentNode = dequeue();
        printf("%d ", currentNode);

    
        for (int i = 0; i < N; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                enqueue(i);        
                visited[i] = true;  
            }
        }
    }
}

int main() {

    int graph[N][N] = {
        {0, 1, 1, 0, 0, 0}, // 0
        {1, 0, 0, 1, 1, 0}, // 1
        {1, 0, 0, 0, 0, 1}, // 2
        {0, 1, 0, 0, 0, 0}, // 3
        {0, 1, 0, 0, 0, 0}, // 4
        {0, 0, 1, 0, 0, 0}  // 5
    };
    
    
    bool visitedDFS[N] = {false}; 
    printf("DFS Ciktisi (Derinlemesine): ");
    DFS(graph, 0, visitedDFS);
    printf("\n");

    front = -1; rear = -1; 

    
    printf("BFS Ciktisi (Genisine):     ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}

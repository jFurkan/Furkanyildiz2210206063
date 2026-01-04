#include <stdio.h>

#define MAX_SIZE 100


int heap[MAX_SIZE];
int size = 0;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



void heapify(int i) {
    int largest = i;          
    int left = 2 * i + 1;     
    int right = 2 * i + 2;    

    
    if (left < size && heap[left] > heap[largest])
        largest = left;

    
    if (right < size && heap[right] > heap[largest])
        largest = right;

    
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest); 
    }
}

void insert(int newNum) {
    if (size == 0) {
        heap[0] = newNum;
        size++;
    } else {
        heap[size] = newNum;
        size++;
        
        
        int i = size - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && heap[i] > heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}


int deleteRoot() {
    if (size == 0) {
        printf("Heap bos!\n");
        return -1;
    }

    int root = heap[0]; 
    
    
    heap[0] = heap[size - 1];
    size--;

  
    heapify(0);

    return root;
}


void printHeap() {
    printf("Heap Dizisi: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    // Test
    insert(3);
    insert(4);
    insert(9);
    insert(5);
    insert(2);

    printf("Ekleme sonrasi (Max Heap):\n");
    printHeap(); 

    printf("\nKok siliniyor (Max eleman): %d\n", deleteRoot());
    printHeap();

    printf("Kok siliniyor (Max eleman): %d\n", deleteRoot());
    printHeap();

    return 0;
}

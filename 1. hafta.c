#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101 


typedef struct {
    int row;
    int col;
    int value;
} term;

int main() {
   
    int denseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    
    term sparseMatrix[MAX_TERMS];

    int i, j;
    int count = 0; 
    int rows = 4;
    int cols = 5;

    /
    int currentTerm = 1; 

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (denseMatrix[i][j] != 0) {
                sparseMatrix[currentTerm].row = i;
                sparseMatrix[currentTerm].col = j;
                sparseMatrix[currentTerm].value = denseMatrix[i][j];
                currentTerm++;
                count++;
            }
        }
    }

   
    sparseMatrix[0].row = rows;
    sparseMatrix[0].col = cols;
    sparseMatrix[0].value = count;

   
    printf("Orijinal Matris:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", denseMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Donusum Sonrasi (Sparse Matrix - Triplet) ---\n");
    printf("Satir\tSutun\tDeger\n");
    printf("-----\t-----\t-----\n");
    
    
    for (i = 0; i <= count; i++) {
        if(i == 0) {
            printf("%d\t%d\t%d\t <--- (Boyut ve Toplam Eleman Bilgisi)\n", 
                   sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
            printf("---------------------\n");
        } else {
            printf("%d\t%d\t%d\n", 
                   sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
        }
    }

    return 0;
}

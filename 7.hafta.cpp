#include <stdio.h>

void elemanSil(int dizi[], int *boyut, int silinecekIndex) {
  
    if (silinecekIndex < 0 || silinecekIndex >= *boyut) {
        printf("Gecersiz index!\n");
        return;
    }

   
    for (int i = silinecekIndex; i < *boyut - 1; i++) {
        dizi[i] = dizi[i + 1];
    }

   
    (*boyut)--;
    
    printf("%d. indexteki eleman silindi.\n", silinecekIndex);
}

int main() {
    int dizi[10] = {10, 20, 99, 30, 40}; 
    int boyut = 5;

   
    elemanSil(dizi, &boyut, 2);

   
    printf("Yeni Dizi: ");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

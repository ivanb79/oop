#include <stdio.h>

int* at(int a[], int i) {
    return &a[i]; 
}

int main() {
    int niz[] = {10, 20, 30, 40, 50};
    int i = 2; 

    printf("Prije: niz[%d] = %d\n", i, niz[i]);

    (*at(niz, i)) += 1;  

    printf("Poslije: niz[%d] = %d\n", i, niz[i]);

    return 0;
}
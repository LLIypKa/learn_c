#include <stdlib.h>
#include <stdio.h>

void swap(int*, int*);

int main(void) {
    int a = 15, b = 71;
    printf("a = %d, b = %d до вызова функции\n", a, b);

    swap(&a, &b);
    printf("a = %d, b = %d после вызова функции\n", a, b);

    return EXIT_SUCCESS;
}

void swap(int* a, int* b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}
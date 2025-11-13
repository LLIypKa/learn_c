#include <stdlib.h>
#include <stdio.h>

unsigned int* increment(void) {
    static unsigned int counter = 0;
    counter++;

    return &counter;
}

unsigned int retrieve(unsigned int* pointer) {
    return *pointer;
}

void sum(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void max(int a, int b) {
    int max = a > b ? a : b;
    printf("from %d and %d bigger %d\n", a, b, max);
}

void min(int a, int b) {
    int min = a < b ? a : b;
    printf("from %d and %d lower %d\n", a, b, min);
}

void func_call(void (*arr[])(int, int), int index) {
    int a = 100, b = 1000;
    arr[index](a, b);
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("%d\n", retrieve(increment()));
    }

    void (*func_ptrs_arr[3])(int, int) = {sum, max, min};
    func_call(func_ptrs_arr, 2);

    return EXIT_SUCCESS;
}


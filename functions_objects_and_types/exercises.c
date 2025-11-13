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

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("%d\n", retrieve(increment()));
    }

    int a = 100, b = 1000;

    void (*function_sum_ptr)(int, int) = sum;
    void (*function_max_ptr)(int, int) = max;
    void (*function_min_ptr)(int, int) = min;

    void (*func_ptrs_arr[3])(int, int) = {function_sum_ptr, function_max_ptr, function_min_ptr};
    for (int i = 0; i < 3; i++) {
        func_ptrs_arr[i](a, b);
    }

    return EXIT_SUCCESS;
}
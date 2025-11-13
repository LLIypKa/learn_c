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

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("%d\n", retrieve(increment()));
    }
    return 0;
}
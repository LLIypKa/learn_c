#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    unsigned int uint; //-корректно
    unsigned ui; //-корректно

    long long int lli; //-корректно
    long long ll; //-корректно

    if (UINT_MAX > INT_MAX) {
        printf("естественно, %ud > %d\n", UINT_MAX, INT_MAX); //ради инетереса, попробуй убрать u в строке формата, и увидишь пример переполнения
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    unsigned int uint; //-корректно
    unsigned ui; //-корректно

    long long int lli; //-корректно
    long long ll; //-корректно

    if (UINT_MAX > INT_MAX) {
        printf("естественно, %u > %d\n", UINT_MAX, INT_MAX); //ради инетереса, попробуй убрать u (замени на d) в строке формата, и увидишь пример переполнения
    }

    ui = UINT_MAX;
    printf("до переноса %u\n", ui);

    ui += 100;
    printf("после переноса (+100) %u\n", ui);

    ui -= 100;
    printf("после переноса (-100) %u\n", ui);

    //for (unsigned int i = n; i >= 0; --i) - почему цикл никогда не кончится

    return EXIT_SUCCESS;
}
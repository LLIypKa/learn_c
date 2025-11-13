#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH_FOR_I 5
#define MAX_LENGTH_FOR_J 3

int main(void) {
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    char str[11];

    for (unsigned int i = 0; i < 10; i++) {
        //str - указатель на первый элемент массива. Из-за наличия операции индексации ([]) выражение
        //str[i] эквивалентно *(str + i)
        str[i] = '0' + i;
    }
    str[10] = '\0';
    printf("%s\n", str);

    int ab[MAX_LENGTH_FOR_I][MAX_LENGTH_FOR_J];

    for (int i = 0; i < MAX_LENGTH_FOR_I; i++) {
        for (int j = 0; j < MAX_LENGTH_FOR_J; j++) {
            ab[i][j] = i * MAX_LENGTH_FOR_J + j;
        }
    }

    //лучше конечно, обойти просто как массив, но тут я хочу показать, что массив в памяти хранится линейно (даже многомерный)
    //в рабочих проектах далеко не всегда такой способ стоит применять 
    //(если важна производительность, либо код, использующий массив, принимает и работает только с указателями - можно)
    int* ab_ptr = &ab[0][0];

    for (int i = 0; i < MAX_LENGTH_FOR_I; i++) {
        for (int j = 0; j < MAX_LENGTH_FOR_J; j++) {
            printf("%d\t", *(ab_ptr + (i * MAX_LENGTH_FOR_J + j)));
        }

        printf("\n");
    }

    printf("\n");
    //можно еще так
    for (int i = 0; i < MAX_LENGTH_FOR_I; i++) {
        for (int j = 0; j < MAX_LENGTH_FOR_J; j++) {
            printf("%d\t", ab_ptr[i * MAX_LENGTH_FOR_J + j]);
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}
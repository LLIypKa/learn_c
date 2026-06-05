#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//если передавать не через указатели, а копированием - то сигнатура бужет выглядеть так:
//write_matrix_to_terminal(size_t, size_t, int [*][*])
void write_matrix_to_terminal(size_t*, size_t*, int (*)[*][*]);

//тут все также нет проверок корректности чтения, т.к. нам здесь нужно показать другие вещи
//вообще VLA РАБотают быстро, но они чрезвычайно опасны, т.к. могут вызвать переполнение стэка, \
нет переносимого способа проверить корректность выделения памяти и некоторые другие особенности \
делают VLA довольно небезопасными, из-за чего их страются избегать (на данный момент они встречаются \
только в узких областях или в устаревшем коде)
int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    FILE* file_with_matrix = fopen("input_matrix.txt", "r");
    size_t lines;
    size_t columns;

    fscanf(file_with_matrix, "%zu", &lines);
    fscanf(file_with_matrix, "%zu", &columns);

    int array[lines][columns];
    
    for(size_t i = 0; i < lines; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            fscanf(file_with_matrix, "%d", &array[i][j]);
        }
    }
    write_matrix_to_terminal(&lines, &columns, &array);

    fclose(file_with_matrix);
    return EXIT_SUCCESS;
}

void write_matrix_to_terminal(size_t* lines, size_t* columns, int (*array)[*lines][*columns])
{
    int total = 0;

    printf("Весь массив\n");
    for(size_t i = 0; i < *lines; i++)
    {
        for(size_t j = 0; j < *columns; j++)
        {
            total += (*array)[i][j];
            //будем считать, что в файле лежат двухзначные числа
            printf("%d\t", (*array)[i][j]);
        }
        printf("\n");
    }
    printf("Сумма элементов массива: %d\n", total);
}
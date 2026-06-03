#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define STRING_DATA_MAX_LENGTH 255

typedef struct 
{
    char name[STRING_DATA_MAX_LENGTH];
    int age;
    char profession[STRING_DATA_MAX_LENGTH];
} person;

void clear_memory(FILE*, person*);

//вообще лучше всегда проверять, что возвращают методы для выделения памяти и для чтения данных/памяти - это поможет избежать крашей
int main(void) 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    //допустим в input.txt лежат данные для структуры person (данные какого-нибудь nagger'а)
    //в таком случае создавать статический объект(-ы) не имеет смысла, т.к. мы не знаем, придут ли данные для него или нет
    //на помощь приходит функция malloc, принимающей аргумент типа size_t - размер выделяемого блока в байтах
    FILE* file_with_data = fopen("input_person_data.txt", "r");
    if (file_with_data == NULL)
    { 
        printf("Ошибка открытия файла\n");
        
        return EXIT_FAILURE;
    }

    person* person1 = malloc(sizeof(person));
    if (person1 == NULL) 
    {
        printf("Ошибка выделения памяти\n");
        clear_memory(file_with_data, person1);
        return EXIT_FAILURE;
    }
    //в работе нужно было бы добавить проверку корректности получения данных (просто тупо проверить, прочитала ли функция то, что требовалось)
    //при помощи if (fgets(person->name, sizeof(person->name), file_with_data) == NULL)
    //также, по-хорошему, надо указать какой длины должен быть прочитанный блок (либу прикрутить длину блока в строку формата) 
    //или, в указанном двумя строками выше if'е добавить вместо sizeof, например, макрос, который как раз для определения размера блока и нужен
    fscanf(file_with_data, "%s", person1->name);
    fscanf(file_with_data, "%d", &person1->age);
    fscanf(file_with_data, "%s", person1->profession);

    printf("Имя: %s\nВозраст: %d\nПрофессия: %s\n", person1->name, person1->age, person1->profession);
    clear_memory(file_with_data, person1);

    //допустим в input.txt лежит первым номером - длина массива, а далее - элементы массива
    //в таком случае создавать статический массив не имеет смысла, т.к. его длина может быть меньше/больше созданной
    //на помощь приходит функция calloc, принимающей аргументы типа size_t - количество элементов и их размер
    FILE* file_with_numbers = fopen("input_numbers.txt", "r");
    if (file_with_numbers == NULL)
    { 
        printf("Ошибка открытия файла с числами\n");
        
        return EXIT_FAILURE;
    }
    int array_length;
    int buff;
    int i = 0;
    fscanf(file_with_numbers, "%d", &array_length);

    int* array = calloc(array_length, sizeof(int));
    if (array == NULL) 
    {
        printf("Ошибка выделения памяти для массива\n");
        fclose(file_with_numbers);
        return EXIT_FAILURE;
    }
    while(fscanf(file_with_numbers, "%d", &buff) != -1 && i < array_length)
    {
        array[i] = buff;
        i++;
    }

    for (int j = 0; j < array_length; j++)
    {
        printf("%d\n", array[j]);
    }
    fclose(file_with_numbers);

    //допустим, нам понадобилось расширить массив - нужна функция realloc
    FILE* file_with_numbers_2 = fopen("input_numbers_2.txt", "r");
    int new_array_block_size;
    int* realloced_array;
    int new_array_length;

    fscanf(file_with_numbers_2, "%d", &new_array_block_size);
    new_array_length = array_length + new_array_block_size;
    if ((array_length + new_array_block_size == 0) 
        || (realloced_array = realloc(array, new_array_length)) == NULL)
    {
        printf("Ошибка переопределения памяти для массива\n");
        free(array);
        fclose(file_with_numbers_2);
        return EXIT_FAILURE;
    }
    else
    {
        array = realloced_array;
    }

    i = array_length;
    while(fscanf(file_with_numbers_2, "%d", &buff) != -1 && i < new_array_length)
    {
        array[i] = buff;
        i++;
    }

    printf("переопределение памяти для массива\n");
    for (int j = 0; j < new_array_length; j++)
    {
        printf("%d\n", array[j]);
    }

    free(array);
    fclose(file_with_numbers_2);
    
    return EXIT_SUCCESS;
}

void clear_memory(FILE* file, person* person)
{
    fclose(file);
    free(person);
}
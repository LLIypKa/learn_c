/*
int do_something(void) {

  FILE *file1, *file2;

  object_t *obj;

  int ret_val = 0; // изначально ожидаем возвращения успешного значения

 

  file1 = fopen("a_file", "w");

  if (file1 == NULL) {

    ret_val = -1;

    goto FAIL_FILE1;

  }

  file2 = fopen("another_file", "w");

  if (file2 == NULL) {

    ret_val = -1;

    goto FAIL_FILE2;

  }

  obj = malloc(sizeof(object_t));

  if (obj == NULL) {

    ret_val = -1;

    goto FAIL_OBJ;

  }

  // Работаем с выделенными ресурсами

 

  // Освобождаем все ресурсы

  free(obj);

FAIL_OBJ: // В противном случае закрываем только то, что мы открывали

  fclose(file2);

FAIL_FILE2:

  fclose(file1);

FAIL_FILE1:

  return ret_val;

}

исходный код

Задание:

Отредактируйте функцию из листинга 5.11 так, чтобы вызывающей стороне было понятно, какой файл нельзя открыть.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int object_t;

int do_something(char** error_message) 
{
    FILE *file1, *file2;
    object_t *obj;
    int ret_val = 0; // изначально ожидаем возвращения успешного значения
    //r только, чтобы проверить, возвращается ли сообщение, для w файлы все равно будут созданы
    file1 = fopen("a_file", "r");
    if (file1 == NULL) 
    {
        ret_val = -1;
        *error_message = "Невозможно открыть файл a_file";
        goto FAIL_FILE1;
    }
    
    file2 = fopen("another_file", "r");
    if (file2 == NULL) 
    {
        ret_val = -1;
        *error_message = "Невозможно открыть файл another_file";
        goto FAIL_FILE2;
    }

    obj = malloc(sizeof(object_t));
    if (obj == NULL) 
    {
        ret_val = -1;
        goto FAIL_OBJ;
    } 
    
    free(obj);

FAIL_OBJ: 
    fclose(file2);

FAIL_FILE2:
    fclose(file1);

FAIL_FILE1:
    return ret_val;
}

int main(void) 
{
    char* message = NULL;

    int result = do_something(&message);
    if (result != 0) 
    {
        printf("%s\n", message);
    }

    return 0;
}
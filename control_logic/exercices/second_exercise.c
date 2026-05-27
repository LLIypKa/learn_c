/*
Измените функцию find_element из листинга 5.13 так, чтобы она возвращала позицию ключа в a. 
Не забудьте вернуть идентификатор ошибки, если ключ не найден.
size_t find_element(size_t len, int arr[len], int key) {
  size_t pos = (size_t)-1;
  // обходим arr и ищем key
  for (size_t i = 0; i < len; ++i) {
    if (arr[i] == key) {
      pos = i;
      break; // выход из цикла
    }
  }
  return pos;
}
*/
//можно вернуть структуру, а не bool тип
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRAY_LENGTH 10

bool find_element(size_t len, int arr[len], int key, size_t* pos) {
    *pos = (size_t) - 1;

    for (size_t i = 0; i < len; ++i) 
    {
        if (arr[i] == key) 
        {
            *pos = i;
            return true;
        }
    }
    
    return false;
}

int main(void) 
{
    int a[ARRAY_LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    size_t position;

    if (find_element(ARRAY_LENGTH, a, key, &position)) 
    {
        printf("Элемент %d найден в позиции %ld\n", key, position);
    }
    else
    {
        printf("Элемент %d не найден\n", key);
    }

    return 0;
}
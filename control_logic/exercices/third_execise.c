/*
. Исправьте оставшийся дефект в функции absolute_value из листинга 5.14.
Листинг 5.14. Функция absolute_value возвращает значение a в любом случае

int absolute_value(int a) {
  if (a < 0) {
    return -a;
  }
  return a;
}
*/

#include <stdio.h>
#include <limits.h>

int absolute_value(int a) {
    if (a < 0 && a != INT_MIN) {
        return -a;
    }

    return a;
}

int main(void)
{
    int a = INT_MIN;

    printf("%d\n", absolute_value(a));

    return 0;
}
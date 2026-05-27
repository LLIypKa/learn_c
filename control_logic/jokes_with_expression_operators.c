#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Rus");

    ; // - это самый простой, нулевой оператор-выражение
    int a = 6; // оператор-выражение: присвоение значения переменной a

    return 0;
}
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main(void) 
{
    printf("Операция дополнения\n");
    setlocale(LC_ALL, "Rus");
    /*
    В архитектуре с 8‑битным char и 32‑битным int переменная uc расширяется до signed int
     (дополнение нулями до 0x000000FF), затем инвертируется в 0xFFFFFF00 - 
     отрицательное значение типа signed int
    */
    unsigned char uc = UCHAR_MAX;
    printf("uc = %d\n", (int)uc);
    int i = ~uc;
    printf("i = %d, uc = %d\n", i, (int)uc);

    printf("Операция сдвига\n");
    unsigned int ii = 10;
    printf("uc = %u\n", ii);
    ii = ii << 6;
    //результат будет равен 40, т.к. для беззнакового a будет справедливо равенство a << b = a*(2^b)
    printf("uc = %u\n", ii);

    printf("Операция битовое И\n");
    int x = 0, y = 1;
    printf("x = %d, y = %d, x & y = %d\n", x, y, x & y);
    x = 1, y = 1;
    printf("x = %d, y = %d, x & y = %d\n", x, y, x & y);

    printf("Операция исключающее ИЛИ\n");
    x = 0, y = 1;
    // x = 0, x = 1, x^y = 1
    printf("x = %d, y = %d, x ^ y = %d\n", x, y, x ^ y);
    x = 1, y = 1;
    // x = 1, x = 1, x^y = 0
    printf("x = %d, y = %d, x ^ y = %d\n", x, y, x ^ y);
    x = 0, y = 0;
    // x = 0, x = 0, x^y = 0
    printf("x = %d, y = %d, x ^ y = %d\n", x, y, x ^ y);

    printf("Операция включающее ИЛИ\n");
    int r = 0, t = 1;
    // r = 0, t = 1, r^t = 1
    printf("r = %d, t = %d, r | t = %d\n", r, y, r | t);
    r = 1, t = 1;
    // r = 1, r = 1, r^t = 1
    printf("r = %d, t = %d, r | t = %d\n", r, y, r | t);
    r = 0, t = 0;
    // r = 0, t = 0, r^t = 0
    printf("r = %d, t = %d, r | t = %d\n", r, y, r | t);

    return 0;
}
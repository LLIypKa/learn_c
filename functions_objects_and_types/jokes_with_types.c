#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");
    //Оба варианта допустимы
    _Bool boolean = 1;
    bool boolen = true;

    wchar_t t = L'з';

    printf("%d %d\n", boolean, boolen);

    printf("%lc\n", t);
    return EXIT_SUCCESS;
}
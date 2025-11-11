#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <wchar.h>

int main(void) {
    setlocale(LC_ALL, "");
    //Оба варианта допустимы
    _Bool boolean = 1;
    bool boolen = true;

    wchar_t t = L'з';
    wchar_t message[] = L"Привет, мир!"; 

    wprintf(L"%d %d\n", boolean, boolen);
    wprintf(L"%lc\n", t);
    wprintf(L"%ls\n", message);

    return EXIT_SUCCESS;
}
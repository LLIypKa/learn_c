//задание для NAGGER - подумай, какой вывод будет у вывода перечислений

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <wchar.h>
#define month_count 12

struct NAGGER {
    int a;
    int b;
};

typedef struct NAGGER nagger;

enum months {
    jan = 1,
    feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum months_v2 {
    jan_v2, feb_v2, mar_v2, apr_v2, may_v2, jun_v2, jul_v2, aug_v2, sep_v2, oct_v2, nov_v2, dec_v2, months_count
};

int main(void) {
    enum months months[] = { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
    enum months_v2 months_v2[] = { jan_v2, feb_v2, mar_v2, apr_v2, may_v2, jun_v2, jul_v2, aug_v2, sep_v2, oct_v2, nov_v2, dec_v2, months_count };

    setlocale(LC_ALL, "");

    nagger nagger;
    //Оба варианта допустимы
    _Bool boolean = 1;
    bool boolen = true;

    wchar_t t = L'з';
    wchar_t message[] = L"Привет, мир!"; 

    wprintf(L"%d %d\n", boolean, boolen);
    wprintf(L"%lc\n", t);
    wprintf(L"%ls\n", message);

    for (int i = 0; i < month_count; i++) {
        wprintf(L"%d\t", months[i]);
    }

    wprintf(L"\n");

    for (int i = 0; i < months_count; i++) {
        wprintf(L"%d\t", months_v2[i]);
    }

    wprintf(L"\n");

    return EXIT_SUCCESS;
}

void g(int j) {
    
}
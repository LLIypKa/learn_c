#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h> 

#define NAGGERS_CATCHPHRASE L"Запомни эту фразу - всё будет, но не сразу"
#define NAGGERS_NAME L"NAGGER"

struct NAGGER {
    wchar_t name[255];
    wchar_t catchphrase[255];
    double money;
};

typedef struct NAGGER nagger;

int main(void) {
    setlocale(LC_ALL, "");

    //тут можно упростить, ничего не изменится, просто я хочу потренироваться с явным указанием выравнивания
    //явно работать с вырваниванием нет смысла, если того не требуют условия - работа с сырой памятью, 
    //с кастомными аллокатарами или какие-нибудь другие специфические условия
    _Alignas(nagger) nagger buffer;
    nagger* nagger = &buffer;

    //для рабочего проекта сюда надо использовать wcsncpy с указанием кол-ва символов, копируемых в nagger->...
    //потому как в реальности, может выйти так, что место, куда копируется инфа, может оказаться меньше самой инфы
    //тут, по-хорошему, нужны либо проверки, либо wcsncpy
    wcscpy(nagger->name, NAGGERS_NAME);
    wcscpy(nagger->catchphrase, NAGGERS_CATCHPHRASE);
    nagger->money = 1000.0;

    wprintf(L"Меня зовут %ls, я всегда говорю \"%ls\", у меня есть %f денег\n", 
        nagger->name, nagger->catchphrase, nagger->money);

    return EXIT_SUCCESS;
}
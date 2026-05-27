#include <stdio.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Rus");

    //самый простой составной оператор 
    {
        static int count = 0;
        count += 1;
        printf("count = %d\n", count);
    }

    //Кстати, ты, кто это читает, поРАБотай маленько - подумай, что значит static у переменной count?
    //Будет ли доступна переменная count за этим блоком? Если нет, то как исправить?

    return 0;
}
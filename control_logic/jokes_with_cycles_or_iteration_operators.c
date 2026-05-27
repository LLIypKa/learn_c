#include <stdio.h>
#include <locale.h>
#define MAIN_PHRASE "6oKoXoDeLL"

typedef struct Person person;

struct Person {
    char* name;
    int age;
};

int main(void)
{
    setlocale(LC_ALL, "");

    int n = 8;
    // бесконечно бы выполнялся этот цикл
    //while (true)
    while (n--) 
    {
        printf("%s\n", MAIN_PHRASE);
    }
    
    printf("DO WHILE\n");
    n = 8;
    //почти то же самое, только выполняется как минимум одна итерация до проверки условия
    //а дальше выполняется пока условие истинно
    do 
    {
        printf("%s\n", MAIN_PHRASE);
    } while(n--);
    
    n = 8;
    printf("FOR\n");
    //обычно используют, когда есть понимание, сколько именно раз нужно выполнить те или иные инструкции
    //этот цикл будет выполняться для каждого i, меньшего n и после каждой итерации i будет увеличиваться на 1
    for (int i = 0; i < n; i++) {
        printf("%s\n", MAIN_PHRASE);
    }
    /*
    равносильно записи
    n = 8; 
    int i = 0;
    while (i < n) 
    {
        ...
        i++;
    }
    */

    return 0;
}
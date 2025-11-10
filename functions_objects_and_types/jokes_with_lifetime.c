//задание для ни...наггера - подумай какой вывод будет у проги

#include <stdlib.h>
#include <stdio.h>

//срок хранения, а равно, и время жизни - все время выполнения программы
//область видимости - файловая => доступен во всем файле
int counter_for_wrapped_cycle = 0;

void update_counter(void);

int main(void) {
    //printf("counter = %d", counter); - АЛААААААРМ! ОШИБКА! 
    //срок хранения - автоматический
    //область видимости - блочная => доступен только в main
    int counter_for_main = 0;
    printf("counter for main = %d, counter for wrapped cycle = %d\n", counter_for_main, counter_for_wrapped_cycle);

    for (int i = 0; i < 5; i++) {
        update_counter();
        for (int j = 0; j < 5; j++) {
            //область видимости - блочная, при том - вложенная
            //время жизни автоматичское => пока выполняется блок
            int wrapped_counter = 0;

            wrapped_counter++;
            counter_for_wrapped_cycle *= 2;
            counter_for_main++;

            printf("\ncounter for main = %d, counter for wrapped cycle = %d, wrapped counter = %d\n", 
                counter_for_main, counter_for_wrapped_cycle, wrapped_counter);
        }
        //wrapped_counter++; - АЛААААРМ!ОШИБКА!
    }

    printf("===counter for main = %d, counter for wrapped cycle = %d===\n", counter_for_main, counter_for_wrapped_cycle);
    return EXIT_SUCCESS;
}

void update_counter(void) {
    //срок хранения, а равно, и время жизни - все время выполнения программы
    //область видимости - только update_counter, т.е. блочная 
    static int counter = 0;

    counter++;
    counter_for_wrapped_cycle++;

    printf("---counter = %d---, counter_for_wrapped_cycle = %d\n", counter, counter_for_wrapped_cycle);
}
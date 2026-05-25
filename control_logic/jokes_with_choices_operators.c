#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <limits.h>

//в работе никогда не дублируй код (точнее,старайся избегать такого) и давай информативные имена названиям
bool save_div(int, int, int*);
bool save_div_v2(int, int, int*);
const char* switch_case_for_week_days(int);

int main(void) 
{
    setlocale(LC_ALL, "");

    int quotient;
    save_div_v2(10, 2, &quotient);

    printf("Результат 10 : 2 = %d\n", quotient);

    int day_number = 4;
    //так, солнце еще не село, так что РАБотай: что нужно сделать, чтобы не было разыменовывания пустого указателя 
    printf("%d день недели - %s\n", day_number, switch_case_for_week_days(day_number));

    return 0;
}

//ля какие комменты могу делать 

/// @brief безопасное деление
/// @param dividend 
/// @param divisor 
/// @param quotient 
/// @return возвращет false, если передан пустой указатель на резултат или нулевой делитель, \
а также при возможном переполнении, true - если всё в порядке с вычислением
bool save_div(int dividend, int divisor, int* quotient)
{
    if (!quotient) 
    {
        return false;
    }

    if ((divisor == 0) || ((dividend == INT_MIN) && (divisor == -1)))
        return false;
    
    *quotient = dividend / divisor;

    /*
    если бы *quotient = dividend / divisor; был бы на уровне с подоператором return false; т.е.:
    if ((divisor == 0) || ((dividend == INT_MIN) && (divisor == -1)))
        return false;
        *quotient = dividend / divisor;

    то прога все равно выполнится (если условие не истинно) =) ну и, если бы не return в if,
     то на этом примере можно было бы сказать, что всё, что идёт после if - 
     выполняется (ну это так и есть, если не брать в расчёт нашу прогу)
    */
    return true;
}

/// @brief безопасное деление v2
/// @param dividend 
/// @param divisor 
/// @param quotient 
/// @return возвращет false, если передан пустой указатель на резултат или нулевой делитель, \
а также при возможном переполнении, true - если всё в порядке с вычислением
bool save_div_v2(int dividend, int divisor, int* quotient)
{
    /*
    суть здесь такая же, только представлено в максимально огромном виде:
    1. если условие if не истинно, то переход к else if
    2. если и else if не истинно, то переход к else
    3. выполняется подоператор else и переход на выполнение инструкций за блоком
    */
    if (!quotient) 
    {
        return false;
    }
    else if ((divisor == 0) || ((dividend == INT_MIN) && (divisor == -1)))
    {
        return false;
    }
    else
    {
        *quotient = dividend / divisor;
        return true;
    }
}

/// @brief возвращает название дня недели по порядковому номеру
/// @param day_number порядковый номен дня недели
const char* switch_case_for_week_days(int day_number) 
{
    //тот, кто читает, поРАБотай маленько - подумай, какого ху...дожественного замысла здесь есть модификатор static  
    static const char* week_days[] =
    {
        "Понедельник",
        "Вторник",
        "Среда",
        "Четверг",
        "Пятница",
        "Суббота",
        "Воскресенье"
    };

    //сам по себе switch-case тот же самый if-else, только управляющее выражение должно иметь целочисленный тип
    switch (day_number)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return *(week_days + day_number - 1);
            break;
        default:
            return NULL;
    }

    /*
    Данный switch-case, не самый показательный, можно и так переписать:
    if (day_number >= 1 && day_number <= 7)
        return week_days[day_number - 1];
    else
        return NULL;
    */
}
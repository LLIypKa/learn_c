#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

union BadPiggiesWithBrokenHouses
{
    struct NafNaf {
        bool has_house;
        int guests_in_house;
    } naf_naf;

    struct NifNif {
        bool has_house;
        double saved_bricks_from_house;
    } nif_nif;

    struct NufNuf {
        bool has_house;
        int met_wolf_count;
    } nuf_nuf;
};

union ascii {
    int digit;
    char letter;
};

int main(void) {
    union BadPiggiesWithBrokenHouses piggies;
    union BadPiggiesWithBrokenHouses* piggies_ptr = &piggies;

    piggies.naf_naf.has_house = true;
    piggies.naf_naf.guests_in_house = 2;

    //теперь Наф-нафа данные будут перезаписаны
    piggies_ptr->nif_nif.has_house = false;
    piggies_ptr->nif_nif.saved_bricks_from_house = 3.5;

    //теперь наф-наф аткивен, а ниф-ниф идёт считать кирпичи дальше
    printf("Guests in NAF-NAF's house count: %d\n", piggies_ptr->naf_naf.guests_in_house);

    piggies_ptr->nuf_nuf.met_wolf_count = 3;
    piggies_ptr->nuf_nuf.has_house = false;

    //кстати пример с поросятами в рабочий код не годится - для этого объединения нужно отдельное поле в каждой структуре,
    //которое обозначило бы последнюю записанную структуру (как варик, можно ещё сделать перечисление с константами 
    // по именам поросят, сделать поле в объединении которе принимало бы одну из констант и по нему определять,
    //какое значение было записано последним), а так этот код - классический пример неопределённого поведения
    //теперь наф-наф аткивен, а нуф-нуф погнал волков гонять
    printf("Guests in NAF-NAF's house count: %d\n", piggies_ptr->naf_naf.guests_in_house);

    //почему вывод разный?
    /*
    на примере объдинения ascii

    памяти будет выделено по максимальному члену объединения. 
    В общем случае - это будет выглядеть так (char - 1 байт, int - 4 байта): (одна клетка - один байт)
    |---------------------------------- |
    |           int digit                         |
    |---------------------------------- |
    |  char   |          |            |          |
    | letter  |          |            |          |
    |---------------------------------- |

    В перовом байте будет болтаться символьное значение, и все 4 могут использоваться для целочисленного значения

    Если создать переменную объединения, например так:
    union ascii code;
    то, так как оба элемента - letter и digit занимают одну и ту же память, то данные фактически одни и те же,
    только при обращении к code.digit данные интерпретируются как объект int, 
    а при обращении к code.letter - как объект char.
    И изменение одного из них приведет к изменению другого.

    code.digit = 120;
    printf("%d - %c \n", code.digit, code.letter);  // 120 - x
    printf("%d - %d \n", code.digit, code.letter);  // 120 - 120

    code.letter = 87;
    printf("%d - %c \n", code.digit, code.letter);  // 87 - W
    */

    return EXIT_SUCCESS;
}

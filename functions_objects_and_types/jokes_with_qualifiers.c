#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int not_const = 1;
    const int const_variable = 2;

    printf("%d %d\n", not_const, const_variable);

    const int* not_const_ptr = &not_const;
    const int* const_variable_ptr = &const_variable;

    *(int*) not_const_ptr += 10; //да и такого то же лучше избегать, хоть и поведение будет вполне определённым
    *(int*) const_variable_ptr += 10; //вот тут будет неопределённое поведение

    printf("%d %d\n", not_const, const_variable);

    return EXIT_SUCCESS;
}
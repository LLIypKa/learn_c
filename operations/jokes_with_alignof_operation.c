#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
#include <assert.h>

int main(void) {
    int arr[4];
    //статическое утверждение
    static_assert(_Alignof(arr) == 4, "unexpected alignment");  
    // динамическое утверждение
    assert(alignof(max_align_t) == 16);

    printf("Alignment of ar = %zu\n", _Alignof(arr));
    printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));

    return 0;

    //Вывод может быть, например \
    Alignment of arr = 4 \
    Alignment of max_align_t = 16 \
    а может и не быть вовсе: Если динамические утверждения включены, \ 
    то программа может не скомпилироваться из-за static_assert, \
    не выполнить динамическое утверждение, ничего не вывести или вывести следующее
}
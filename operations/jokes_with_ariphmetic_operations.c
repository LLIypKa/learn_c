#include <stdio.h>
#include <limits.h>

int main(void)
{
    //попробуй скомпилировать, увидишь ошибку " warning: integer overflow in expression of type ‘int’ results in ‘0’"
    //а почему ты ее увидишь?
    printf("%d\n", INT_MIN % (-1));
    return 0;
}
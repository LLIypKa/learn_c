/*
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
int closedir(DIR *dirp) {
  free(dirp->d_buf);
  free(dirp);
  return close(dirp->d_fd); // dirp уже освобождена
}

Исправьте ошибку с использованием освобожденной памяти в листинге 6.4.
*/

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int closedir(DIR *dirp) {
    int result = close(dirp->d_fd);

    free(dirp->d_buf);
    free(dirp);

    return result; // dirp уже освобождена
}
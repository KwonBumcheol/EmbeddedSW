#include <stdio.h>

int main(void) {
    int num = 13;
    int *ptr;
    int **dptr;

    ptr = &num;
    dptr = &ptr;

    printf("%p, %d\n", &num, num);
    printf("%p, %p, %u\n", ptr, &ptr, *ptr);
    printf("%p, %p, %p, %u\n", dptr, &dptr, *dptr, **dptr);

    return 0;
}
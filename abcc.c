#include <stdio.h>

int main(void) {
    int num = 13;
    int *ptr; // 포인터
    int **dptr; // 이중 포인터

    ptr = &num;
    dptr = &ptr;

    printf("%p, %d\n", &num, num);
    printf("%p, %p, %u\n", ptr, &ptr, *ptr);
    printf("%p, %p, %p, %u\n", dptr, &dptr, *dptr, **dptr);

    return 0;
}
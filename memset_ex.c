#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long *ptr = (long*)malloc(sizeof(long));

    memset(ptr, 0x5A, 4); // 메모리 복사 0x5A -> ptr

    printf("0x %lX\n", *ptr); // 5A 5A 5A 5A

    free(ptr);

    return 0;
}
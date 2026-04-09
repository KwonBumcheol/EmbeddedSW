#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long *ptr = (long*)malloc(sizeof(long));

    memset(ptr, 0x5A, 4);

    printf("0x %lX\n", *ptr);

    free(ptr);

    return 0;
}
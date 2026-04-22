#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int num = 7;

    ptr = &num;
    printf("%p, %d\n", ptr, *ptr);

    ptr = malloc(sizeof(int)); // ptr = (int*)malloc(sizeof(int));

    *ptr = 123;
    printf("%p, %d\n", ptr, *ptr);

    free(ptr);

    return 0;
}
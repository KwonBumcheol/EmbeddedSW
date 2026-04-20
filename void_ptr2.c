#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(20);

    printf("%p\n", ptr);
    printf("%p\n", (int*)ptr + 1); // +4byte
    printf("%p\n", (char*)ptr + 1); // +1byte

    free(ptr);

    return 0;
}
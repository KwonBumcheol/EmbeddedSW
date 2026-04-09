#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *add(int a, int b) {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = a + b;
    printf("addr = %p\n", ptr);

    return ptr;
}

void *mem_alloc(void) {
    void *ptr = malloc(256);
    return ptr;
}

int main() {
    // int *ptr;

    // ptr = add(7, 8);

    // printf("%d\n", *ptr);

    // free(ptr);

    char *s1;
    s1 = (char*)mem_alloc();

    strcpy(s1, "Hello, Pointer!!");
    printf("%s\n", s1);

    free(s1);

    int *num;
    num = (int*)mem_alloc();

    num[0] = 0x5A;
    num[1] = 0xA5;
    printf("num[0] = 0x%x, num[1] = 0x%x\n", num[0], num[1]);

    free(num);

    return 0;
}
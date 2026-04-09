#include <stdio.h>

int main() {
    int num = 17;
    void *ptr;

    ptr = &num;
    printf("%p\n", ptr);
    // *ptr = 20;
    ptr++;
    printf("%p\n", ptr);

    return 0;
}
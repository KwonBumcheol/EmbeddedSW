#include <stdio.h>

int main() {
    int arr[5] = { 100, 200, 300, 400, 500 };
    int *ptr;

    ptr = arr;

    printf("*(ptr + 1) = %d\n", *(ptr + 1));
    printf("*(ptr + 3) = %d, %p\n", *(ptr + 3), ptr);
    printf("*(++ptr) = %d, %p\n", *(++ptr), ptr);
    printf("*++ptr = %d, %p\n", *++ptr, ptr);
    printf("*ptr++ = %d, %p\n", *ptr++, ptr);
    printf("*ptr = %d, %p\n", *ptr, ptr);

    return 0;
}
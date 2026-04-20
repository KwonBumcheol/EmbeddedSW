#include <stdio.h>

int main() {
    int arr[5] = { 100, 200, 300, 400, 500 };
    int *ptr;

    ptr = arr; // ptr = &arr[0]

    printf("*(ptr + 1) = %d\n", *(ptr + 1)); // 200
    printf("*(ptr + 3) = %d, %p\n", *(ptr + 3), ptr); // 400
    printf("*(++ptr) = %d\n", *(++ptr)); // 200
    printf("*++ptr = %d\n", *++ptr); // 300
    printf("*ptr++ = %d\n", *ptr++); // 300
    printf("*ptr = %d, %p\n", *ptr, ptr); // 400

    return 0;
}
#include <stdio.h>

int main() {
    int arr[5] = { 100, 200, 300, 400, 500 };
    int *ptr1, *ptr2, *ptr3;

    ptr1 = arr; // ptr1 = &arr[0] = 100
    ptr2 = ptr1 + 2; // ptr2 = &arr[2] = 300
    ptr3 = ptr1 + 4; // ptr3 = &arr[4] = 500

    printf("ptr1: value = %d, addr = %p\n", *ptr1, ptr1);
    printf("ptr2: value = %d, addr = %p\n", *ptr2, ptr2);
    printf("ptr3: value = %d, addr = %p\n", *ptr3, ptr3);

    ptr1++;
    ptr3--;

    printf("ptr1: value = %d, addr = %p\n", *ptr1, ptr1);
    printf("ptr3: value = %d, addr = %p\n", *ptr3, ptr3);

    return 0;

}
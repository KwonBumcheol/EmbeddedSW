#include <stdio.h>

int main() {
    int arr[5] = { 0x12, 0x34, 0x56, 0x78, 0x90 };
    int *ptr = arr;

    printf("0x%x, 0x%x, 0x%x\n", *ptr, *arr, arr[0]);

    printf("%d, %d\n", (int)sizeof(arr), (int)sizeof(ptr));

    return 0;
}
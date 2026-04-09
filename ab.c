#include <stdio.h>

int main() {
    int *ptr;
    int num1 = 7;
    int num2 = 13;

    ptr = &num1;
    printf("%p, %p\n", ptr, &num1);
    printf("%d\n", *ptr);

    ptr = &num2;
    printf("%p, %p\n", ptr, &num2);
    printf("%d\n", *ptr); // 역참조 *p -> num2의 주소로 가서 값 참조

    printf("%d\n", (int)sizeof(ptr));
    printf("%d\n", (int)sizeof(char*));
    printf("%d\n", (int)sizeof(char));
    printf("%d\n", (int)sizeof(int));
    printf("%d\n", (int)sizeof(float)); // 32bit
    printf("%d\n", (int)sizeof(double)); // 64bit
    printf("%d\n", (int)sizeof(long));
}
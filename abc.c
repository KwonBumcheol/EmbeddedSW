#include <stdio.h>

int main() {
    int num = 17;
    void *ptr;

    ptr = &num;
    printf("%p\n", ptr);
    // *ptr = 20; // 컴파일 에러
    ptr++; // 1byte 증가
    printf("%p\n", ptr);

    return 0;
}
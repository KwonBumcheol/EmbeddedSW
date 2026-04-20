#include <stdio.h>

int main() {
    void *ptr;
    char str = 'a';
    int i_num = 371;
    float f_num = 3.141592;

    ptr = &str;
    printf("%c\n", *(char*)ptr); // (char*)ptr = 주소값 -> *(char*)ptr = 주소가 참조하는 값 가져와

    ptr = &i_num;
    printf("%d\n", *(int*)ptr);

    ptr = &f_num;
    printf("%f\n", *(float*)ptr);

    return 0;
}
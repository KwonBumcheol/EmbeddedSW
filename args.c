#include <stdio.h>
#include <stdlib.h> /* exit() 함수 사용하기 위함 */

/* 모든 명령줄 인수를 출력한다. */
int main(int argc, char *argv[]) {
    int i;

    for (i = 0; i < argc; i++) /* 모든 명령줄 인수 출력*/ 
        printf("argv[%d]: %s \n", i, argv[i]);

    exit(0); /* 프로그램 종료 */
}
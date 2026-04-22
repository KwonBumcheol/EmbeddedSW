#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 부모 프로세스가 두 개의 자식 프로세스를 생성 */

int main() {
    int pid1, pid2;

    pid1 = fork(); // 부모, 자식1
    if (pid1 == 0) {
        printf("[Child 1]: Hello, world pid=%d\n", getpid()); // 자식 프로세스
        exit(0); // 자식1 종료
    }

    pid2 = fork(); // 부모, 자식2
    if (pid2 == 0) {
        printf("[Child 2]: Hello, world pid=%d\n", getpid()); // 자식 프로세스
        exit(0); // 자식2 종료
    }
}
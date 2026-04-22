#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 부모 프로세스가 자식 프로세스를 생성하고 서로 다른 메시지를 프린트 */

int main() {
    int pid;
    pid = fork();

    if (pid == 0) { // 자식 프로세스는 리턴값 = 0 
        printf("[Child]: Hello, world pid=%d\n", getpid()); // 자식 프로세스
    } else {
        printf("[Parent]: Hello, world pid=%d\n", getpid()); // 부모 프로세스
    }
}
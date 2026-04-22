#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() {
    int pid1, pid2, child, status;

    printf("[%d] 부모 프로세스 시작\n", getpid());
    pid1 = fork(); // 부모, 자식 1
    if (pid1 == 0) {
        printf("[%d] 자식 프로세스[1] 시작\n", getpid());
        sleep(1);
        printf("[%d] 자식 프로세스[1] 종료\n", getpid());
        exit(1); // 자식 프로세스 1 종료 - 정보는 남음
    }

    pid2 = fork(); // 부모, 자식 2
    if (pid2 == 0) {
        printf("[%d] 자식 프로세스[2] 시작\n", getpid());
        sleep(2);
        printf("[%d] 자식 프로세스[2] 종료\n", getpid());
        exit(2); // 자식 프로세스 2 종료 - 정보는 남음
    }

    // 자식 프로세스 #1의 종료를 기다린다.
    child = waitpid(pid1, &status, 0); // pid1 에 해당하는 자식 프로세스(1) 종료 대기 -> 회수
    printf("[%d] 자식 프로세스 #1 %d 종료\n", getpid(), child); // 부모, 자식1 정보
    printf("\t종료 코드 %d\n", status>>8); // exit(1) -> 1 출력
}
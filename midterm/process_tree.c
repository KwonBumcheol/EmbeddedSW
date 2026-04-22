#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() {
    int pid1, pid2, child, child2, status;

    printf("Parent 시 작\n");
    pid1 = fork(); // 부모, 자식 1
    if (pid1 == 0) {
        printf("Child1 시 작\n");
        sleep(1);
        printf("Child1 종 료\n");
        exit(1); // 자식 프로세스 1 종료 - 정보는 남음
    }

    pid2 = fork(); // 부모, 자식 2
    if (pid2 == 0) {
        printf("Grandchild 시 작\n");
        printf("Grandchild 종 료\n");
        exit(2); // 자식 프로세스 2 종료 - 정보는 남음
    }

    // 자식 프로세스 #1의 종료를 기다린다.
    child = waitpid(pid2, &status, 0); // pid1 에 해당하는 자식 프로세스(1) 종료 대기 -> 회수
    child = waitpid(pid1, &status, 0); // pid1 에 해당하는 자식 프로세스(1) 종료 대기 -> 회수

    child2 = fork(); // 부모, 자식 2
    if (child2 == 0) {
        printf("Child2 시 작\n");
        printf("Child2 종 료\n");
        exit(3); // 자식 프로세스 2 종료 - 정보는 남음
    }
    child = waitpid(child2, &status, 0); // pid1 에 해당하는 자식 프로세스(1) 종료 대기 -> 회수
    printf("Parent 종 료\n"); // 부모, 자식1 정보
}
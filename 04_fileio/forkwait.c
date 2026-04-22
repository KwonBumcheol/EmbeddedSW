#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() {
    int pid, child, status;
    printf("[%d] 부모 프로세스 시작\n", getpid()); // 현재 프로세스 - 부모

    pid = fork(); // 부모, 자식
    if (pid == 0) {
        printf("[%d] 자식 프로세스 시작\n", getpid()); // 자식 프로세스
        exit(1); // 자식 종료 - 상위 8bit 저장
    }

    child = wait(&status); // (좀비상태로 남은) 자식 프로세스 1개가 끝날 때가지 대기 -> 부모가 회수해서 자식 종료
    printf("[%d] 자식 프로세스 %d 종료\n", getpid(), child);
    printf("\t종료 코드 %d\n", status>>8);
}
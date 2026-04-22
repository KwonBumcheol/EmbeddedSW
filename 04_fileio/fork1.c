#include <stdio.h>
#include <unistd.h>

/* 자식 프로세스 생성 */
int main() {
    int pid;
    printf("[%d] 프로세스 시작 \n", getpid()); // 현재 프로세스 ID - 부모 프로세스
    pid = fork(); // 현재 프로세스 복사 -> pid 저장
    printf("[%d] 프로세스: 리턴값 %d\n", getpid(), pid); // 부모, 자식 
}
// 명령줄 인수로 받은 명령어를 제한시간 내에 실행
// execute3.c 프로그램을 알람 시그널을 이용해 확장
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int pid; // 자식 프로세스 pid 저장용

void alarmHandler(); 

int main(int argc, char *argv[]) {
    int child, status, limit;

    signal(SIGALRM, alarmHandler);  // 알람 시그널 핸들러 등록

    // 첫번째 입력값 -> 정수로 변경 -> limit 저장
    sscanf(argv[1], "%d", &limit); // ./tlimit 10 ls -> argv[1] = "10", limit = 10

    alarm(limit); // 10초후 SIGALRM 발생

    pid = fork(); // 부모, 자식 생성
    if (pid == 0) { // 자식 프로세스
        execvp(argv[2], &argv[2]); // argv[1] ~ NULL 사용
        fprintf(stderr, "%s:실행 불가\n", argv[2]);
    } else { // 부모 프로세스
        child = wait(&status);
        printf("[%d] 자식 프로세스 %d 종료\n", getpid(), pid);
    }
}

void alarmHandler() {
    printf("[알람] 자식 프로세스 %d 시간 초과\n", pid);
    kill(pid, SIGINT); //
}
// 시그널을 이용해 자식 프로세스 제어
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int pid1, pid2;

    pid1 = fork(); // 부모, 자식1 생성 - 프로세스1 실행
    if (pid1 == 0) { // 자식1
        while(1) {
            sleep(1);
            printf("프로세스 [1] 실행\n");
        }
    }

    pid2 = fork(); // 부모, 자식2 생성 - 프로세스2 실행
    if (pid2 == 0) { // 자식2
        while(1) {
            sleep(1);
            printf("프로세스 [2] 실행\n");
        }
    }

    sleep(2);
    kill(pid1, SIGSTOP); // 프로세스 일시정지
    sleep(2);
    kill(pid1, SIGCONT); // 정지된 프로세스 재실행
    sleep(2);
    kill(pid2, SIGSTOP);
    sleep(2);
    kill(pid2, SIGCONT);
    sleep(2);
    kill(pid1, SIGKILL); // 프로세스 강제 종료
    kill(pid2, SIGKILL);
}
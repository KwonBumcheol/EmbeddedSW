#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pause() - 시그널 받기 전까지 해당 프로세스 잠들게 함
#include <signal.h>

void intHandler();

int main() {
    signal(SIGINT, intHandler); // ctrl+c 누르면 시그널 발생 -> intHandler 실행

    while(1) {
        pause();
    }
    printf("실행되지 않음\n");

}

void intHandler(int signo) {
    printf("인터럽트 시그널 처리\n");
    printf("시그널 번호: %d\n", signo);
    exit(0);
}
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction newact; // 새로운 시그널 등록
struct sigaction oldact; // 기존 시그널 저장용

void sigint_handler(int signo);

int main() {
    newact.sa_handler = sigint_handler; // 새 시그널 처리기 등록
    sigfillset(&newact.sa_mask);        // newact 시그널 외에는 차단하도록 마스크

    sigaction(SIGINT, &newact, &oldact); // ctrl+c -> newact 실행(sigint_handler), oldact에 기존 시그널 저장(ctrl+c 누르면 종료)

    while(1) {
        printf("Ctrl-C를 눌러 보세요 !\n");
        sleep(1);
    }
}

void sigint_handler(int signo) {
    printf("%d 번 시그널 처리!\n", signo);
    printf("또 누르면 종료됩니다.\n");
    sigaction(SIGINT, &oldact, NULL); // ctrl+c 실행시 발생하는 시그널을 기존으로 변경(oldact)
}
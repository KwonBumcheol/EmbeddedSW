#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> // signal()

void alarmHandler();

int main() {
    signal(SIGALRM, alarmHandler); // SIGALRM 시그널 발생시 -> alarmHandler 함수 실행
    alarm(5); // 5초뒤 알람 시그널 발생

    printf("무한 루프\n");
    while(1) {
        sleep(1);
        printf("1초 경과\n");
    }
    printf("실행되지 않음\n");

}

void alarmHandler() {
    printf("일어나세요\n");
    exit(0);
}
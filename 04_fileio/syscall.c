#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int status;
    if ((status = system("date")) < 0)
        perror("system() 오류");
    
    // WEXITSTATUS: 정상종료시 0, 오류시 오류번호 리턴
    printf("종료코드 %d\n", WEXITSTATUS(status));

    if ((status = system("hello")) < 0)
        perror("system() 오류");
    printf("종료코드 %d\n", WEXITSTATUS(status));

    if ((status = system("who; exit 44")) < 0)
        perror("system() 오류");
    printf("종료코드 %d\n", WEXITSTATUS(status));
}
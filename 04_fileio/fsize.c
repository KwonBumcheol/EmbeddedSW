#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 512

/* 파일 크기를 계산한다. */
int main(int argc, char* argv[]) {
    char buffer[BUFSIZE];
    int fd;
    ssize_t nread;  // read() 읽은 바이트 수 저장, ssize_t 음수 불가능
    long total = 0;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        perror(argv[1]);

    /* 파일의 끝에 도달할 때까지 반복해서 읽으면서 파일 크기 계산 */
    while((nread = read(fd, buffer, BUFSIZE)) > 0) // fd 파일 읽고 buffer에 저장, 최대 BUFSIZE 만큼 읽기
        total += nread;
    close(fd);

    printf("%s 파일 크기: %ld 바이트 \n", argv[1], total);
    exit(0);
}
#include <stdio.h> 
#include <stdlib.h> // exit()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // open()
#include <unistd.h> // close()

int main(int argc, char* argv[]) {
    int fd;
    if ((fd = open(argv[1], O_RDWR)) == -1) // 파일 열기 - 읽고 쓰기 + 실패시 -1 반환
        printf("파일 읽기 오류\n");
    else
        printf("파일 %s 열기 성공: %d\n", argv[1], fd); // 파일 디스크립터 3 출력 (0, 1, 2는 이미 표준이라 3부터 시작)
    
    close(fd);
    exit(0);
}
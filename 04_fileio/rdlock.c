#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"
// 여러 프로세스가 같은 학생 DB 파일을 동시에 접근할 수 있을 때,

// * 조회 중인 레코드가 다른 프로세스에 의해 수정되지 않게
// * 안전하게 읽기 위해

// 읽기 잠금(read lock) 을 사용하는 거야.

/* 잠금을 이용한 학생 데이터베이스 질의 프로그램 */
int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;
    struct flock lock;

    if (argc < 2) {
        fprintf(stderr, "사용법: %s 파일\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("\n검색할 학생의 학번 입력:");
    while (scanf("%d", &id) == 1) {
        lock.l_type = F_RDLCK; // 읽기 잠금 설정 - 다른 프로세스 읽기만 가능
        lock.l_whence = SEEK_SET; // 기준 위치 - 파일 시작점
        lock.l_start = (id - START_ID) * sizeof(record); // 잠글 구간의 시작위치
        lock.l_len = sizeof(record); // 잠글 길이 - 레코드 1개 크기만큼 잠금

        // 잠금 걸기 - lock 구조체에서 한 잠금 설정 + fd 잠금 가능할 때까지 대기
        if (fcntl(fd, F_SETLKW, &lock) == -1) { // 읽기 잠금 실패
            perror(argv[1]);
            exit(3);
        }

        // 파일 위치 이동
        lseek(fd, (id - START_ID) * sizeof(record), SEEK_SET);

        // 레코드 읽기
        if ((read(fd, &record, sizeof(record)) > 0) && (record.id != 0))
            printf("이름: %s\t 학번: %d\t 점수: %d\n", record.name, record.id, record.score);
        else
            printf("레코드 %d 없음\n", id);
        
        // 잠금 해제
        lock.l_type = F_UNLCK; // 잠금 해제 설정
        fcntl(fd, F_SETLK, &lock); // 잠금 해제 수행
        printf("\n검색할 학생의 학번 입력:");
    }

    close(fd);
    exit(0);
}
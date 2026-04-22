#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* 잠금 함수를 이용한 학생 데이터베이스 수정 프로그램 */
int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;

    if (argc < 2) {
        fprintf(stderr, "사용법: %s 파일\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    /* ── 파일 전체 잠금 (프로그램 시작 시) ── */
    lseek(fd, 0, SEEK_SET);           // 파일 시작으로 이동
    if (lockf(fd, F_LOCK, 0) == -1) { // 0 = 현재 위치부터 파일 끝까지 전체
        perror(argv[1]);
        exit(3);
    }
    /* ─────────────────────────────────────── */

    printf("\n수정할 학생의 학번 입력:");
    while (scanf("%d", &id) == 1) {
        lseek(fd, (long)(id - START_ID) * sizeof(record), SEEK_SET);

        if ((read(fd, &record, sizeof(record)) > 0) && (record.id != 0)) {
            printf("이름: %s\t 학번: %d\t 점수: %d\n", record.name, record.id, record.score);

            printf("새로운 점수: ");
            scanf("%d", &record.score);

            lseek(fd, -(long)sizeof(record), SEEK_CUR);
            write(fd, &record, sizeof(record));
        } else {
            printf("레코드 %d 없음\n", id);
        }

        printf("\n수정할 학생의 학번 입력:");
    }

    /* ── 파일 전체 잠금 해제 (프로그램 종료 시) ── */
    lseek(fd, 0, SEEK_SET);
    lockf(fd, F_ULOCK, 0);
    /* ─────────────────────────────────────────── */

    close(fd);
    exit(0);
}
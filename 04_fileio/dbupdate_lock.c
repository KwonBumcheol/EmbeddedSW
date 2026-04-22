#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

// dbupdate.c 에서 수정시 rdlock.c 에서 수정(접근) 불가 - lock

/* 학생 정보를 입력받아 해당 학생 레코드를 수정한다. */
int main(int argc, char *argv[]) {
    int fd, id;
    char c;
    struct student record;
    struct flock lock;                          // ← 추가: 잠금 구조체

    if (argc < 2) {
        fprintf(stderr, "사용법: %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("수정할 학생의 학번 입력:");
        if (scanf("%d", &id) == 1) {

            /* ── 쓰기 잠금 설정 ── */
            lock.l_type   = F_WRLCK;                           // 쓰기 잠금
            lock.l_whence = SEEK_SET;
            lock.l_start  = (long)(id - START_ID) * sizeof(record); // 해당 레코드 위치
            lock.l_len    = sizeof(record);                    // 레코드 1개 크기

            if (fcntl(fd, F_SETLKW, &lock) == -1) {           // 잠금 가능할 때까지 대기
                perror("write lock 실패");
                exit(3);
            }
            /* ─────────────────── */

            lseek(fd, (long)(id - START_ID) * sizeof(record), SEEK_SET);

            if ((read(fd, &record, sizeof(record)) > 0) && (record.id != 0)) {
                printf("학번: %8d\t 이름: %4s\t 점수: %4d\n",
                       record.id, record.name, record.score);
                printf("새로운 점수: ");
                scanf("%d", &record.score);

                lseek(fd, (long)-sizeof(record), SEEK_CUR);
                write(fd, &record, sizeof(record));
            } else {
                printf("레코드 %d 없음\n", id);
            }

            /* ── 쓰기 잠금 해제 ── */
            lock.l_type = F_UNLCK;
            fcntl(fd, F_SETLK, &lock);
            /* ─────────────────── */

        } else printf("입력 오류");

        printf("계속하시겠습니까?(Y/N)");
        scanf(" %c", &c);
    } while (c == 'Y');

    close(fd);
    exit(0);
}
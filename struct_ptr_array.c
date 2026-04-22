#include <stdio.h>
#include <stdlib.h>

struct Pos { // 8byte
    int x; // 4byte
    int y; // 4byte
};

int main() {
    struct Pos p[3]; // 8 x 3 = 24byte
    struct Pos *ptr[3]; // 8 x 3 = 24byte

    for(int i = 0; i < sizeof(ptr)/sizeof(struct Pos*); i++) // sizeof(struct Pos*) -> (64bit 시스템 기준) 포인터 한개 크기(8byte) => i < 24 / 8
        ptr[i] = malloc(sizeof(struct Pos));  // 4 + 4 = 8byte

    for(int i = 0; i < sizeof(p)/sizeof(struct Pos); i++) {
        p[i].x = (i + 1) * 10; p[i].y = (i + 1) * 10;
        ptr[i]->x = (i + 1) * 10; ptr[i]->y = (i + 1) * 10;
    }

    for(int i = 0; i < sizeof(p)/sizeof(struct Pos); i++)
        printf("p[%d].x = %d, p[%d].y = %d\n", i, p[i].x, i, p[i].y);

    for(int i = 0; i < sizeof(ptr)/sizeof(struct Pos*); i++)
        printf("ptr[%d]->x = %d, ptr[%d]->y = %d\n", i, ptr[i]->x, i, ptr[i]->y);

    for(int i = 0; i < sizeof(ptr)/sizeof(struct Pos*); i++)
        free(ptr[i]);

    return 0;
}
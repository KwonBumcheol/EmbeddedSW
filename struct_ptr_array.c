#include <stdio.h>
#include <stdlib.h>

struct Pos {
    int x;
    int y;
};

int main() {
    struct Pos p[3];
    struct Pos *ptr[3];

    for(int i = 0; i < sizeof(ptr)/sizeof(struct Pos*); i++)
        ptr[i] = (struct Pos*)malloc(sizeof(struct Pos));

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
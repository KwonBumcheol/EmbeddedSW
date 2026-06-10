#include <stdio.h>
#include <pthread.h>

int x = 0;
pthread_mutex_t lock; // 접근제한 자원 - 잠금장치(lock)

void *thread_func(void *arg) {
    for (int i = 0; i < 100000; i++) {
        // 임계구역
        pthread_mutex_lock(&lock); // 스레드 1개만 들어갈 수 있음 - t1 끝나면 -> t2 스레드 실행
        x++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL); // 뮤텍스 초기화

    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("x = %d\n", x);

    pthread_mutex_destroy(&lock);
}
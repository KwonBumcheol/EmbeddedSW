#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

// void 포인터를 통해 데이터를 주고 받음
void *threadFunction(void *value) {
    int *x = (int *)value; // 전달된 데이터를 int 포인터로 형변환

    while (*x < 5) { // x값이 5보다 작을 때
        usleep(10); // 10us동안 sleep
        (*x)++; // x 값 1 증가
    }

    return x; // 포인터 x를 반환 (void라 전부 받을 수 있다)
}

int main() {
    int x = 0, y = 0;
    pthread_t thread;

    if (pthread_create(&thread, NULL, &threadFunction, &x) != 0) {
        cout << "Failed to create the thread" << endl;
        return 1;
    }

    // 스레드가 성공적으로 생성됨
    while (y < 5) {
        cout << "The value of x= " << x << " and y= " << y++ << endl;
        usleep(10);
    }

    void *result;
    pthread_join(thread, &result); // pthread 종료될 때까지 대기
    int *z = (int *)result;
    cout << "Final: x= " << x << " y= " << y << " and z= " << *z << endl;
    return 0;
}
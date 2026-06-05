// g++ pthreads.cpp -o threads -pthread
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

// void 포인터를 통해 어떤 타입이든지 데이터를 주고 받음 - pthread_create()로 실행할 함수 형태 -> void *함수이름(void *매개변수)
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
    pthread_t thread; // 스레드 정보 저장

    if (pthread_create(&thread, NULL, &threadFunction, &x) != 0) { // 스레드 생성 - threadFunction 함수를 새 스레드에서 실행, 그 함수에 &x 전달
        cout << "Failed to create the thread" << endl;
        return 1;
    }

    // 스레드가 성공적으로 생성됨 - main 스레드 동시 실행
    while (y < 5) {
        cout << "The value of x= " << x << " and y= " << y++ << endl;
        usleep(10);
    }

    void *result;
    pthread_join(thread, &result); // pthread 종료될 때까지 대기, result <- x 주소 들어감(threadFunction 에 return x)
    int *z = (int *)result; // void* -> int* 형변환 -> z 저장
    cout << "Final: x= " << x << " y= " << y << " and z= " << *z << endl;
    return 0;
}
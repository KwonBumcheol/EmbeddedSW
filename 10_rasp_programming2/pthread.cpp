// g++ pthreads.cpp -o threads -pthread
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

// void 포인터를 통해 어떤 타입이든지 데이터를 주고 받음 - pthread_create()로 실행할 함수 형태 -> void *함수이름(void *매개변수)
void *threadFunction(void *value) { // value = x의 주소값 == 0X1000
    int *x = (int *)value; // x = value가 가진 주소값 저장 -> main의 x값 == 0

    while (*x < 5) { // x값이 5보다 작을 때
        usleep(10); // 10us동안 sleep
        (*x)++; // x 값 1 증가
    }

    return x; // 포인터 x를 반환 (void라 전부 받을 수 있다)
}

int main() {
    int x = 0, y = 0;
    pthread_t thread; // 스레드 정보 저장

    if (pthread_create(&thread, NULL, &threadFunction, &x) != 0) { // 스레드 생성 - threadFunction(&x) 실행, x = main의 x주소 == 0x1000
        cout << "Failed to create the thread" << endl;
        return 1;
    }

    // 스레드가 성공적으로 생성됨 - main 스레드 동시 실행
    while (y < 5) {
        cout << "The value of x= " << x << " and y= " << y++ << endl;
        usleep(10);
    }

    void *result;
    pthread_join(thread, &result); // thread 종료될 때까지 대기, result = main의 x 주소(return x)
    int *z = (int *)result; // void* -> int* 형변환 -> *z 에 main의 x값 저장
    cout << "Final: x= " << x << " y= " << y << " and z= " << *z << endl;
    return 0;
}
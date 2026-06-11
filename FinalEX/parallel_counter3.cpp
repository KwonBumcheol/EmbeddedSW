// g++ parallel_counter3.cpp -o counter3 -pthread
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

struct CounterData {
    int id;        // 카운터 번호
    int count;     // 현재 카운트 값
    int limit;     // 목표 카운트 값
};

void *counterFunction(void *arg) {
    CounterData *data = (CounterData *)arg;

    while (data->count < data->limit) {
        usleep(100000); // 0.1초 대기
        data->count++;

        cout << "Counter " << data->id
             << " = " << data->count << endl;
    }

    return data;
}

int main() {
    pthread_t t1, t2, t3;

    CounterData c1 = {1, 0, 5};
    CounterData c2 = {2, 0, 5};
    CounterData c3 = {3, 0, 5};

    pthread_create(&t1, NULL, counterFunction, &c1);
    pthread_create(&t2, NULL, counterFunction, &c2);
    pthread_create(&t3, NULL, counterFunction, &c3);

    void *result1;
    void *result2;
    void *result3;

    pthread_join(t1, &result1);
    pthread_join(t2, &result2);
    pthread_join(t3, &result3);

    CounterData *r1 = (CounterData *)result1;
    CounterData *r2 = (CounterData *)result2;
    CounterData *r3 = (CounterData *)result3;

    cout << "Final Counter " << r1->id << " = " << r1->count << endl;
    cout << "Final Counter " << r2->id << " = " << r2->count << endl;
    cout << "Final Counter " << r3->id << " = " << r3->count << endl;

    return 0;
}
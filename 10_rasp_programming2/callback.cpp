#include <stdio.h> /* /usr/include/stdio.h */
#include <iostream>
using namespace std;

typedef int (*CallbackType)(int); // (int)매개변수로 받고 int를 반환하는 함수 포인터 타입을 CallbackType이라는 이름으로 부르겠다 -> int 함수이름(int x)

int squareCallback(int x) { // 제곱 계산하는 콜백함수
    return x*x;
}

int cubeCallback(int x) { // 세제곱
    return x*x*x;
}

int doMath(int num, CallbackType callback) {
    return callback(num); // 전달된 함수를 호출
}

int main() {
    cout << "Math program -- the value of 5: " << endl;
    cout << "->squared is: " << doMath(5, &squareCallback); // squareCallback(5)
    cout << "->cubed is: " << doMath(5, &cubeCallback) << endl;
    return 0;
}
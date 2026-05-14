#include <stdio.h> /* /usr/include/stdio.h */
#include <iostream>
using namespace std;

typedef int (*CallbackType)(int); // 구문을 깔끔하게 정리하기 위해 사용

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
    cout << "->squared is: " << doMath(5, &squareCallback) << endl;
    cout << "->cubed is: " << doMath(5, &cubeCallback) << endl;
    return 0;
}
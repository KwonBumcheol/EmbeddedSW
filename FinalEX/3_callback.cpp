#include <iostream>
using namespace std;

typedef int (*CallbackType)(int);

int squareCallback(int x) {
    return x * x;
}

int cubeCallback(int x) {
    return x * x * x;
}

int doubleCallback(int x) {
    return x * 2;
}

int main() {
    CallbackType callbacks[3] = {
        squareCallback,
        cubeCallback,
        doubleCallback
    };

    for (int i = 0; i < 3; i++) {
        cout << callbacks[i](5) << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

typedef void (*CallbackType)();

void onButtonPressed() {
    cout << "버튼이 눌렸습니다." << endl;
}

void onSensorDetected() {
    cout << "센서가 감지되었습니다." << endl;
}

void onError() {
    cout << "에러가 발생했습니다." << endl;
}

void runEvent(int eventType, CallbackType buttonCb, CallbackType sensorCb, CallbackType errorCb) {
    if (eventType == 1) {
        buttonCb();
    } else if (eventType == 2) {
        sensorCb();
    } else {
        errorCb();
    }
}

int main() {
    runEvent(1, onButtonPressed, onSensorDetected, onError);
    runEvent(2, onButtonPressed, onSensorDetected, onError);
    runEvent(3, onButtonPressed, onSensorDetected, onError);

    return 0;
}
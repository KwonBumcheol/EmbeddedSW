// sudo ./pwr_callback
#include <iostream>
#include <fstream>
using namespace std;

typedef void (*CallbackType)();

void setHeartbeat() {
    ofstream trigger("/sys/class/leds/PWR/trigger");
    trigger << "heartbeat";
}

void turnOffControl() {
    ofstream trigger("/sys/class/leds/PWR/trigger");
    trigger << "none";

    ofstream brightness("/sys/class/leds/PWR/brightness");
    brightness << "0";
}

void runEvent(CallbackType callback) {
    callback();
}

int main() {
    cout << "PWR LED trigger 변경" << endl;

    runEvent(setHeartbeat);

    return 0;
}
#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <cstdint>
using namespace std;

string display(uint8_t a) { // 10진수 -> 2진수
    stringstream ss;
    ss << setw(3) << (int)a << "(" << bitset<8>(a) << ")";
    return ss.str();
}

int main() {
    uint8_t a = 25, b = 5; // 8 bits unsigned is in the range 0 to 255 
    cout << "A is " << display(a) << " and B is " << display(b) << endl;
    cout << "A & B (AND) is " << display(a & b) << endl;  // 1
    cout << "A | B (OR)  is " << display(a | b) << endl;  // 29
    cout << "  ~A  (NOT) is " << display(~a) << endl;     // 비트반전 -> 230
    cout << "A ^ B (XOR) is " << display(a ^ b) << endl;  // 서로 다르면 1, 같으면 0 -> 28
    cout << "A << 1(LSL) is " << display(a << 1) << endl; // 00011001 << 1 -> 00110010 -> 50 == 25*2
    cout << "B >> 1(LSR) is " << display(b >> 1) << endl; // 00000101 >> 1 -> 00000010 -> 2 == 정수 나눗셈 5/2
    cout << "1 << 8(LSL) is " << display(1 << 8) << endl; // warning!!!! - 오버플로우 발생 1 00000000
    return 0;
}
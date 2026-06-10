#include <iostream>
#include "odd_even.hpp"

using namespace std;

void print_odd_even(int n) {
    if (n % 2 == 0) {
        cout << n << "은 짝수입니다." << endl;
    } else {
        cout << n << "은 홀수입니다." << endl;
    }
}
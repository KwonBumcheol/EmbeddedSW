#include <iostream>
#include "cpp_intgr.hpp"
using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void print_primes(int n) {
    cout << "소수: ";

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
}

// 3의 배수
// void print_multiples_of_three(int n) {
//     cout << "3의 배수: ";

//     for (int i = 1; i <= n; i++) {
//         if (i % 3 == 0) {
//             cout << i << " ";
//         }
//     }

//     cout << endl;
// }

void print_odd_even(int n) {
    if (n % 2 == 0) {
        cout << n << "은 짝수입니다." << endl;
    } else {
        cout << n << "은 홀수입니다." << endl;
    }
}
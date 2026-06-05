// 2번 C++ 코드로 python binding 하기

#include <iostream>
#include <cmath>
using namespace std;

double integrate (double a, double b, int n) {
        double sum = 0, dx = (b - a)/n;
        
        for (int i = 0; i < n; i++) {
            sum += sin((a + i) * dx);
        }
        return sum * dx;
}

// cpp_intgr.so 를 ctypes에서 사용하기 위한 조건 - name mangling(C++) -> extern "C" 사용으로 함수 이름 고정
// extern "C" {
//     double integrate (double a, double b, int n) {
//         double sum = 0, dx = (b - a)/n;
        
//         for (int i = 0; i < n; i++) {
//             sum += sin((a + i) * dx);
//         }
//         return sum * dx;
//     }
// }

int main() {
    cout << integrate(0, 3.141592, 100000) << endl;
    return 0;
}
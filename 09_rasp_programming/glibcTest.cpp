#include <gnu/libc-version.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <pwd.h>
#include <cstdlib>
#include <sys/stat.h>
#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

int main() {
    // 시스템 정보를 얻기 위해 헬퍼 함수를 사용
    cout << "The GNU libc version is: " << gnu_get_libc_version << endl;
    
}
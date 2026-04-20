# 리눅스 C 프로그래밍 함수 정리
> 임베디드SW 2주차 ~ 6주차 강의자료 통합본

---

## 1. 파일 입출력 (File I/O)
> 관련 헤더: `<unistd.h>`, `<fcntl.h>`, `<sys/types.h>`, `<sys/stat.h>`

---

### `open`
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *path, int oflag, [mode_t mode]);
```
- 파일을 열거나 생성한다
- 성공 시 파일 디스크립터(양의 정수) 반환, 실패 시 `-1` 반환

| oflag | 설명 |
|-------|------|
| `O_RDONLY`   | 읽기 전용 |
| `O_WRONLY`   | 쓰기 전용 |
| `O_RDWR`     | 읽기/쓰기 |
| `O_APPEND`   | 파일 끝에 추가 |
| `O_CREAT`    | 파일 없으면 생성 (mode 필요) |
| `O_TRUNC`    | 기존 내용 삭제 |
| `O_EXCL`     | `O_CREAT`와 함께 사용, 이미 있으면 오류 |
| `O_NONBLOCK` | 넌블로킹 모드 |
| `O_SYNC`     | 물리적 디스크 쓰기 후 반환 |

---

### `creat`
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creat(const char *path, mode_t mode);
```
- 파일을 생성하고 쓰기 전용으로 연다
- `open(path, O_WRONLY|O_CREAT|O_TRUNC, mode)` 와 동일
- 성공 시 파일 디스크립터 반환, 실패 시 `-1` 반환

---

### `close`
```c
#include <unistd.h>

int close(int fd);
```
- `fd`가 나타내는 파일을 닫는다
- 성공 시 `0`, 실패 시 `-1` 반환

---

### `read`
```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbytes);
```
- `fd`에서 `nbytes`만큼 읽어 `buf`에 저장한다
- 성공 시 읽은 바이트 수, 파일 끝(EOF) 시 `0`, 실패 시 `-1` 반환

---

### `write`
```c
#include <unistd.h>

ssize_t write(int fd, void *buf, size_t nbytes);
```
- `buf`의 `nbytes`만큼 데이터를 `fd`에 쓴다
- 성공 시 쓴 바이트 수, 실패 시 `-1` 반환

---

### `lseek`
```c
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
```
- 파일 위치 포인터(현재 파일 위치)를 이동시킨다
- 성공 시 현재 위치(바이트 오프셋) 반환, 실패 시 `-1` 반환

| whence | 설명 |
|--------|------|
| `SEEK_SET` | 파일 시작 기준 |
| `SEEK_CUR` | 현재 위치 기준 |
| `SEEK_END` | 파일 끝 기준 |

```c
lseek(fd, 0L, SEEK_SET);                    // 파일 처음으로
lseek(fd, 0L, SEEK_END);                    // 파일 끝으로
lseek(fd, n*sizeof(record), SEEK_SET);      // n+1번째 레코드로
lseek(fd, -(long)sizeof(record), SEEK_CUR); // 이전 레코드로
```

---

### `dup`
```c
#include <unistd.h>

int dup(int oldfd);
```
- `oldfd`의 복제본인 새로운 파일 디스크립터를 생성하여 반환한다
- 실패 시 `-1` 반환

---

### `dup2`
```c
#include <unistd.h>

int dup2(int oldfd, int newfd);
```
- `oldfd`를 `newfd`에 복제한다 (표준 입출력 재지정에 활용)
- 실패 시 `-1` 반환

```c
dup2(fd, 1); // fd를 표준출력(1)으로 복제
```

---

## 2. 파일 및 레코드 잠금 (File & Record Locking)
> 관련 헤더: `<fcntl.h>`, `<unistd.h>`

---

### `fcntl`
```c
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int fcntl(int fd, int cmd, struct flock *lock);
```
- `cmd`에 따라 잠금 검사 또는 잠금 설정/해제를 수행한다
- 성공 시 `0`, 실패 시 `-1` 반환

| cmd | 설명 |
|-----|------|
| `F_GETLK`  | 잠금 상태 검사 |
| `F_SETLK`  | 잠금 설정 또는 해제 (비블로킹) |
| `F_SETLKW` | 잠금 설정 또는 해제 (블로킹 — 잠금 가능할 때까지 대기) |

**struct flock 구조체**
```c
struct flock {
    short l_type;   // F_RDLCK(읽기), F_WRLCK(쓰기), F_UNLCK(해제)
    off_t l_start;  // 잠금 시작 위치 (바이트 오프셋)
    short l_whence; // 기준 위치: SEEK_SET, SEEK_CUR, SEEK_END
    off_t l_len;    // 잠금 길이 (0이면 파일 끝까지)
    pid_t l_pid;    // 프로세스 번호
};
```

**잠금 호환 규칙**

| 현재 잠금 상태 | 읽기 잠금 요청 | 쓰기 잠금 요청 |
|---------------|--------------|--------------|
| 없음 | ✅ 승인 | ✅ 승인 |
| 하나 이상 읽기 잠금 | ✅ 승인 | ❌ 거절 |
| 하나의 쓰기 잠금 | ❌ 거절 | ❌ 거절 |

---

### `lockf`
```c
#include <unistd.h>

int lockf(int fd, int cmd, off_t len);
```
- 현재 파일 위치부터 `len` 길이만큼의 영역에 잠금 설정/검사/해제를 한다
- 성공 시 `0`, 실패 시 `-1` 반환

| cmd | 설명 |
|-----|------|
| `F_LOCK`  | 잠금 설정 (이미 잠긴 경우 해제될 때까지 대기) |
| `F_TLOCK` | 잠금 설정 (이미 잠긴 경우 즉시 `-1` 반환) |
| `F_TEST`  | 잠금 여부 검사 (잠금 없으면 `0`, 있으면 `-1`) |
| `F_ULOCK` | 잠금 해제 |

---

## 3. 프로세스 제어 (Process Control)
> 관련 헤더: `<unistd.h>`, `<sys/wait.h>`

---

### `fork`
```c
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);
```
- 현재 프로세스를 복제하여 새로운 자식 프로세스를 생성한다
- 자식 프로세스에게는 `0`, 부모 프로세스에게는 자식 PID를 반환
- 실패 시 `-1` 반환

> ⚠️ `fork()` 이후 자식에게 **상속되지 않는 것**: fork() 반환값, PID, 파일 잠금, 설정된 알람 및 시그널

---

### `wait`
```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```
- 자식 프로세스 중 하나가 끝날 때까지 기다린다
- 종료 코드가 `status`에 저장되며, 종료된 자식의 PID를 반환한다
- 정상 종료 시: `status` 하위 8bit = `0`, 상위 8bit = `exit()` 인수 값

---

### `waitpid`
```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *statloc, int options);
```
- 특정 자식 프로세스(또는 그룹)가 종료될 때까지 기다린다

| pid 값 | 동작 |
|--------|------|
| `pid > 0`  | 해당 PID의 자식이 종료되기를 기다린다 |
| `pid == 0` | 호출자와 같은 프로세스 그룹의 자식을 기다린다 |
| `pid == -1`| 임의의 자식 프로세스를 기다린다 (`wait()`과 동일) |
| `pid < -1` | `|pid|`와 같은 그룹 ID의 자식을 기다린다 |

---

### `execl` / `execlp` / `execv` / `execvp`
```c
#include <unistd.h>

int execl (char *path, char *arg0, ..., char *argn, NULL);
int execlp(char *file, char *arg0, ..., char *argn, NULL);
int execv (char *path, char *argv[]);
int execvp(char *file, char *argv[]);
```
- 현재 프로세스의 코드/데이터/힙/스택을 새 프로그램으로 교체한다
- 성공 시 리턴하지 않음, 실패 시 `-1` 반환

| 구분 | 설명 |
|------|------|
| `l` vs `v` | `l` = 인수를 리스트로 전달 / `v` = 배열로 전달 |
| `path` vs `file` | `path` = 절대/상대 경로 사용 / `file` = PATH 환경변수로 탐색 |

---

### `system`
```c
#include <stdlib.h>

int system(const char *cmdstring);
```
- 내부적으로 `fork` / `exec` / `waitpid`를 호출하여 shell 명령어를 실행한다
- `/bin/sh -c cmdstring` 형태로 실행된다

| 반환값 | 의미 |
|--------|------|
| 명령어 종료 코드 | 정상 실행 |
| `-1` | `fork` 또는 `waitpid` 실패 |
| `127` | `exec` 실패 |

---

## 4. 프로세스 ID 관련
> 관련 헤더: `<unistd.h>`, `<sys/types.h>`

---

### `getpid`
```c
#include <unistd.h>

pid_t getpid(void);
```
- 호출한 프로세스의 PID를 반환한다

---

### `getppid`
```c
#include <unistd.h>

pid_t getppid(void);
```
- 호출한 프로세스의 부모 프로세스 PID를 반환한다

---

### `getpgrp`
```c
#include <sys/types.h>
#include <unistd.h>

pid_t getpgrp(void);
```
- 호출한 프로세스의 프로세스 그룹 ID(GID)를 반환한다

---

### `setpgid`
```c
#include <sys/types.h>
#include <unistd.h>

int setpgid(pid_t pid, pid_t pgid);
```
- 프로세스 `pid`의 프로세스 그룹 ID를 `pgid`로 설정한다
- 성공 시 `0`, 실패 시 `-1` 반환
- `pid == pgid` 또는 `pid=0, pgid=0` → 새로운 그룹 리더가 됨

```c
setpgid(0, 0); // 새 프로세스 그룹 생성 후 리더가 됨
```

---

## 5. 프로세스 종료
> 관련 헤더: `<stdlib.h>`

---

### `exit`
```c
#include <stdlib.h>

void exit(int status);
```
- 열린 스트림을 모두 닫고(`fclose`), 출력 버퍼를 디스크에 쓴 후(`fflush`) 프로세스를 정상 종료한다
- 종료 코드(exit code)를 부모 프로세스에게 전달한다
- `atexit()`로 등록된 exit 처리기를 **등록된 역순**으로 호출한다

---

### `_exit`
```c
#include <stdlib.h>

void _exit(int status);
```
- 뒷정리 없이 프로세스를 즉시 종료시킨다
- exit 처리기 호출 및 버퍼 플러시를 수행하지 않는다

---

### `atexit`
```c
#include <stdlib.h>

int atexit(void (*func)(void));
// returns: 0 if OK, nonzero on error
```
- exit 처리기(exit handler)를 등록한다
- 프로세스당 최대 **32개**까지 등록 가능
- `exit()` 호출 시 등록된 **역순**으로 처리기가 호출된다
- `func`: 등록할 함수의 포인터(이름)

---

## 6. 프로세스 사용자 ID 관련
> 관련 헤더: `<sys/types.h>`, `<unistd.h>`

---

### `getuid` / `geteuid` / `getgid` / `getegid`
```c
#include <sys/types.h>
#include <unistd.h>

uid_t getuid(void);   // 프로세스의 실제 사용자 ID 반환
uid_t geteuid(void);  // 프로세스의 유효 사용자 ID 반환
uid_t getgid(void);   // 프로세스의 실제 그룹 ID 반환
uid_t getegid(void);  // 프로세스의 유효 그룹 ID 반환
```

| 함수 | 설명 |
|------|------|
| `getuid()`  | 프로세스를 실행시킨 사용자의 ID |
| `geteuid()` | 현재 유효한 사용자 ID (파일 접근권한 검사 시 사용) |
| `getgid()`  | 프로세스를 실행시킨 사용자의 그룹 ID |
| `getegid()` | 현재 유효한 그룹 ID |

---

### `setuid` / `seteuid` / `setgid` / `setegid`
```c
#include <sys/types.h>
#include <unistd.h>

int setuid(uid_t uid);   // 프로세스의 실제 사용자 ID를 uid로 변경
int seteuid(uid_t uid);  // 프로세스의 유효 사용자 ID를 uid로 변경
int setgid(gid_t gid);   // 프로세스의 실제 그룹 ID를 gid로 변경
int setegid(gid_t gid);  // 프로세스의 유효 그룹 ID를 gid로 변경
```
- 성공 시 `0`, 실패 시 `-1` 반환

---

## 7. 동적 메모리 관리
> 관련 헤더: `<stdlib.h>`

---

### `malloc`
```c
#include <stdlib.h>

void *malloc(size_t size);
```
- `size` 바이트의 메모리를 힙(heap)에서 동적으로 할당하여 포인터를 반환한다
- 할당된 메모리는 **초기화되지 않는다**
- 성공 시 할당된 메모리의 시작 주소 반환, 실패 시 `NULL` 반환

```c
int *ptr = (int*)malloc(sizeof(int) * 10);
```

---

### `calloc`
```c
#include <stdlib.h>

void *calloc(size_t num, size_t size);
```
- `(num × size)` 바이트의 메모리를 힙에서 할당하고 **0으로 초기화**하여 반환한다
- 성공 시 할당된 메모리의 시작 주소 반환, 실패 시 `NULL` 반환

```c
int *ptr = (int*)calloc(10, sizeof(int));
```

---

### `realloc`
```c
#include <stdlib.h>

void *realloc(void *ptr, size_t size);
```
- `ptr`이 가리키는 메모리를 `size` 바이트만큼 재할당하여 반환한다
- 기존 데이터는 보존되며, 증가한 영역은 초기화되지 않는다
- 성공 시 재할당된 메모리의 시작 주소 반환, 실패 시 `NULL` 반환

```c
ptr = (int*)realloc(ptr, sizeof(int) * 20);
```

---

### `free`
```c
#include <stdlib.h>

void free(void *ptr);
```
- `ptr`이 가리키는 동적 할당된 메모리를 해제한다
- `malloc` / `calloc` / `realloc`으로 할당된 메모리에만 사용한다
- 해제 후 댕글링 포인터 방지를 위해 `NULL` 초기화 권장

```c
free(ptr);
ptr = NULL;
```

---

## 8. 메모리 조작
> 관련 헤더: `<string.h>`

---

### `memcpy`
```c
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n);
```
- `src`에서 `dest`로 `n` 바이트를 복사한다
- 동일 영역(자기 자신)에 대한 복사는 **불가능** → `memmove` 사용 권장
- 성공 시 `dest` 포인터 반환

---

### `memmove`
```c
#include <string.h>

void *memmove(void *dest, const void *src, size_t n);
```
- `src`에서 `dest`로 `n` 바이트를 복사한다
- 동일 영역(자기 자신)에 대한 복사도 **안전하게 처리 가능**
- 성공 시 `dest` 포인터 반환

---

### `memset`
```c
#include <string.h>

void *memset(void *dest, int c, size_t n);
```
- `dest`가 가리키는 메모리의 `n` 바이트를 값 `c`로 초기화한다
- `malloc()`으로 할당받은 메모리를 특정 값으로 초기화할 때 주로 사용
- 성공 시 `dest` 포인터 반환

```c
memset(ptr, 0, sizeof(int) * 10); // 0으로 초기화
```

---

### `memcmp`
```c
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n);
```
- `s1`과 `s2`가 가리키는 메모리의 `n` 바이트를 비교한다

| 반환값 | 의미 |
|--------|------|
| 양의 정수 | `s1 > s2` |
| `0` | `s1 == s2` |
| 음의 정수 | `s1 < s2` |

---

## 9. 헤더 파일 요약

| 헤더 파일 | 포함 함수 및 타입 |
|-----------|-----------------|
| `<sys/types.h>` | `pid_t`, `off_t`, `uid_t`, `gid_t`, `mode_t` 등 기본 타입 |
| `<sys/stat.h>`  | 파일 상태 관련 (`open()` 사용 시) |
| `<fcntl.h>`     | `open()`, `fcntl()`, `O_*` 플래그, `F_*` 명령 |
| `<unistd.h>`    | `close()`, `read()`, `write()`, `lseek()`, `dup()`, `dup2()`, `fork()`, `exec*()`, `getpid()`, `getppid()`, `getpgrp()`, `setpgid()`, `getuid()`, `geteuid()`, `getgid()`, `getegid()`, `setuid()`, `seteuid()`, `setgid()`, `setegid()`, `lockf()` |
| `<sys/wait.h>`  | `wait()`, `waitpid()`, `WEXITSTATUS()` 등 매크로 |
| `<stdlib.h>`    | `system()`, `exit()`, `_exit()`, `atexit()`, `malloc()`, `calloc()`, `realloc()`, `free()` |
| `<string.h>`    | `memcpy()`, `memmove()`, `memset()`, `memcmp()` |

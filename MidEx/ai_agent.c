#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 16

/* LLM 응답을 파싱해서 명령어 배열로 변환 */
void parse_command(char *response, char *args[]) {
    int i = 0;
    args[i++] = strtok(response, " "); // " " 기준으로 문자열을 배열로 자름 - 1번
    while ((args[i++] = strtok(NULL, " ")) && i < MAX_ARGS); // " " 기준으로 문자열을 배열로 자름, 더이상 없으면 NULL - 반복
    args[i] = NULL; // 마지막 배열에 NULL 삽입
}

/* 도구 실행 후 종료 코드 반환 */
int run_tool(char *args[]) {
    int pid = fork();
    if (pid == 0) { // 자식 프로세스
        execvp(args[0], args);
        fprintf(stderr, "%s: 실행 불가\n", args[0]);
        exit(127);  // 실행 실패
    }

    int status;
    wait(&status);
    return status >> 8;  // exit 코드 반환
}

int main() {
    // LLM이 "ls -l /tmp" 라고 응답했다고 가정
    char response[] = "ls -l /tmp";
    char *args[MAX_ARGS];

    parse_command(response, args);

    printf("[Agent] 도구 실행: %s\n", args[0]);
    int result = run_tool(args); // 종료코드 반환, 
    printf("[Agent] 종료 코드: %d\n", result);

    // result == 0 → 성공 → 다음 단계 진행
    // result != 0 → 실패 → 재시도 or 다른 도구 선택
    if (result == 0)
        printf("[Agent] 성공 → 다음 단계 실행\n");
    else
        printf("[Agent] 실패 → 재시도 필요\n");
}
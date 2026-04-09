#include <stdio.h>
#include <string.h>

#define MALE 0
#define FEMALE 1

struct Person {
    char name[20];
    int age;
    char gender;
    char major[20];
} p1;

int main() {
    strcpy(p1.name, "권범철");
    p1.age = 26;
    p1.gender = MALE;
    strcpy(p1.major, "사물인터넷");
    printf("이름: %s\n", p1.name);
    printf("나이: %d\n", p1.age);
    printf("성별: %s\n", (p1.gender == 0) ? "남" : "여");
    printf("전공: %s\n", p1.major);

    // struct Person p2 = {"나영희", 23, FEMALE, "경영학과"};
    // // struct Person p2 = {.name = "나영희", .age = 23, .gender = FEMALE, .major = "경영학과"};

    // printf("이름: %s\n", p2.name);
    // printf("나이: %d\n", p2.age);
    // printf("성별: %s\n", (p2.gender == 0) ? "남" : "여");
    // printf("전공: %s\n", p2.major);

    return 0;
}
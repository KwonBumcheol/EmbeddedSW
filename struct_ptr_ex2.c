#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALE 0
#define FEMALE 1

struct Person {
    char name[20];
    int age;
    char gender;
    char major[20];
};

int main() {
    struct Person p1;
    struct Person *ptr;

    ptr = &p1;

    strcpy(ptr->name, "권범철");
    ptr->age = 26;
    ptr->gender = MALE;
    strcpy(ptr->major, "사물인터넷");

    printf("이름: %s\n", p1.name);
    printf("나이: %d\n", p1.age);
    printf("성별: %s\n", (p1.gender == 0) ? "남" : "여");
    printf("전공: %s\n", p1.major);

    printf("이름: %s\n", ptr->name);
    printf("나이: %d\n", ptr->age);
    printf("성별: %s\n", (ptr->gender == 0) ? "남" : "여");
    printf("전공: %s\n", ptr->major);

    return 0;
}
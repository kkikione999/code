#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//malloc的三步走
//申请指针有没有申请失败
//谁申请，谁释放
//释放后的指针赋值为NULL

//一下是一个学生的档案系统

typedef struct student_massage
{
    int id;
    char* name;
    int age;
    int score;
}STU_MSdef;


void student_massage_input(STU_MSdef* stums)
{
    STU_MSdef temp_ms;
    printf("ID:");
    scanf("%d", &temp_ms.id);
    printf("name:");
    temp_ms.name = malloc(sizeof(char)*1024);
    if(temp_ms.name == NULL)
        exit(1);
    scanf("%s", temp_ms.name);
    printf("age:");
    scanf("%d", &temp_ms.age);
    printf("score:");
    scanf("%d", &temp_ms.score);

    stums->id =  temp_ms.id;
    stums->name = malloc(sizeof(char)*strlen(temp_ms.name)+1);
    strcpy(stums->name, temp_ms.name);
    stums->age = temp_ms.age;
    stums->score = temp_ms.score;

    free(temp_ms.name);
    temp_ms.name = NULL;

}
void student_massage_output(STU_MSdef* stums)
{
    printf("ID: %d\n", stums->id);
    printf("name: %s\n", stums->name);
    printf("age: %d\n", stums->age);
    printf("score: %d\n", stums->score);

}


int main()
{
    int student_num;
    printf("please enter student number:");
    scanf("%d", &student_num);
    STU_MSdef stu_ms[student_num];

    for(int i = 0; i<student_num; i++)
        student_massage_input(&stu_ms[i]);
    for(int i = 0; i<student_num; i++)
    {
        student_massage_output(&stu_ms[i]);
        free(stu_ms[i].name);
        stu_ms[i].name = NULL;
    }
    exit(0);
}
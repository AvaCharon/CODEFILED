#include<stdio.h>
#define N 30
#define Project 6
typedef struct date
{
    int year;
    int month;
    int day;
}Date;
typedef struct student
{
    int number;
    char name[10];
    Date birthday;
    int scores[Project];
}Student;
void Input(Student stu[],int n);

int main(void)
{
    int n;
    Student stu[N];
    printf("How many students?\n");
    scanf("%d",&n);
    Input(stu,n);
    return 0;
}

void Input(Student stu[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Input the number and name of the No.%d student\n",i+1);
        scanf("%d%d",&stu[i].number,&stu[i].name);
        printf("Input birthday of this student\n");
        scanf("%d%d%d",&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day);
        for(int j=0;j<Project;j++)
        {
            printf("Input the score of the No.%d project of this student.\n",j+1);
            scanf("%d",&stu[i].scores[j]);
        }
    }
    return ;
}
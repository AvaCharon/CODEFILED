#include<stdio.h>
/*
int main(void)
{
    struct stu
    {
        int number;
        char name[10];
        int score[4];
    };
    
    return 0;
}
*/

typedef struct date
    {
        int year ;
        int month;
        int day ;
    }Date;//Date==struct date
void fun(struct date *b)
{
    (*b).year=2021;
    b->month=11;
    b->day=1;
    return;
}
int main(void)
{
    Date a;
    a.year=2020;
    a.month=10;
    a.day=1;
    printf("%d%d%d\n",a.year,a.month,a.day);
    fun(&a);
    printf("%d%d%d\n",a.year,a.month,a.day);
    return 0;
}
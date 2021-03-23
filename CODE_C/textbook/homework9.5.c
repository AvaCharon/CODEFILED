#include<stdio.h>
int yeard[2][12]={{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
int DayofYear(int year,int month, int day);
void MonthDay(int year,int yearDay,int *pMonth,int *pDay);
int main(void)
{
    int n,year,month=0,day=0,yearDay;
    int *pMonth=&month;
    int *pDay=&day;
    while (n!=3)
    {
        printf("1.year/month/day->yearDay\n2.yearDay->year/month/day\n3.Exit\nPlease enter your choice:");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            scanf("%d%d%d",&year,&month,&day);
            printf("Day %d.\n",DayofYear(year,month,day));
            break;
        case 2:
            scanf("%d%d",&year,&yearDay);
            MonthDay(year,yearDay,pMonth,pDay);
            printf("Month %d Day %d.\n",*pMonth,*pDay);
            break;
        case 3:
            break;
        }
    }
    return 0;
}

int DayofYear(int year,int month, int day)
{
    int leap=0,result=0;
    if(year%4==0&&year%100!=0)leap=1;
    else if(year%400==0)leap=1;
    if(leap==1)
    {
        for(int i=0;i<month-1;i++)
        {
            result=result+yeard[0][i];
        }
    }
    else
    {
        for(int i=0;i<month-1;i++)
        {
            result=result+yeard[1][i];
        }
    }
    result=result+day;
    return result;
}
void MonthDay(int year,int yearDay,int *pMonth,int *pDay)
{
    int leap=0,i=0,result=0,num=0,j=1;
    if(year%4==0&&year&100!=0)leap=1;
    else if(year%400)leap=1;
    if(leap==1)
    {
        do
        {
            if(num>0)i++;
            result=result+yeard[0][i];
            num++;
        } while (result<=yearDay);
        result=result-yeard[0][i];
        *pMonth=i+1;
        for(;j<yeard[0][i];j++)
        {
            if(result+j==yearDay)
            {
                *pDay=j;
                break;
            }
        }
    }
    else
    {
        do
        {
            if(num>0)i++;
            result=result+yeard[1][i];
            num++;
        } while (result<=yearDay);
        result=result-yeard[1][i];
        *pMonth=i+1;
        for(;j<yeard[1][i];j++)
        {
            if(result+j==yearDay)
            {
                *pDay=j;
                break;
            }
        }
    }
    return;
}
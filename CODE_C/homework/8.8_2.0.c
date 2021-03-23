#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int feedback[40];
void getscore(void);//获取打分
float Mean(int str[]);//求平均数
float Median(int str[]);//求中位数
int Mode(int str[]);//求众数

int main(void)
{
    getscore();
    printf("Grade\tCount\tHistogram\n");
    for(int i=0;i<40;i++)
    {
        printf("%d\t%d\t",i+1,feedback[i]);
        for(int j=0;j<feedback[i];j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    printf("The average is %f.\nThe median is %f.\nThe mode is %d.\n",Mean(feedback),Median(feedback),Mode(feedback));
    return 0;
}

void getscore(void)
{
    srand((unsigned)time(NULL));
    for(int i=0;i<40;i++)
    {
        double x;
        x=rand()%11;
        feedback[i]=x;
    }
}

float Mean(int str[])
{
    int total=0;
    for(int i=0;i<40;i++)
    {
        total=total+str[i];
    }
    return (total/40);
}

float Median(int str[])
{
    for(int i=0;i<40;i++)
    {
        for(int k=i;k<40;k++)
        {
            if(str[i]<str[k])
            {
                int temp=str[i];
                str[i]=str[k];
                str[k]=temp;
            }
        }
    }
    if(str[19]==str[20])
    {
        return str[19];
    }
    else
    {
        return ((str[19]+str[20])/2);
    }
}

int Mode(int str[])
{
    int maxcounts=0;
    int counts[11]={0};
    for(int i=0;i<40;i++)
    {
        switch(feedback[i])
        {
            case 0:counts[0]++;break;
            case 1:counts[1]++;break;
            case 2:counts[2]++;break;
            case 3:counts[3]++;break;
            case 4:counts[4]++;break;
            case 5:counts[5]++;break;
            case 6:counts[6]++;break;
            case 7:counts[7]++;break;
            case 8:counts[8]++;break;
            case 9:counts[9]++;break;
            case 10:counts[10]++;break;
        }
    }
    for(int j=1;j<11;j++)
     {
        if(counts[j]>counts[maxcounts])
        {
                maxcounts=j;
         }
     }
     return maxcounts;
}
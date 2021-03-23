#include<stdio.h>
#include<math.h>

int feedback[40]={3,3,4,5,3,4,5,7,8,3,2,8,8,8,8,8,5,6,8,4,10,9,9,4,3,7,7,6,6,6,6,5,4,3,2,2,1,9,9,8};
float Mean(int str[]);//求平均数
float Median(int str[]);//求中位数
int Mode(int str[]);//求众数

int main(void)
{
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

float Mean(int str[])
{
    int total=0;
    for(int i=0;i<40;i++)
    {
        total=total+str[i];
    }
    return ((float)total/40);
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
        return ((float)(str[19]+str[20])/2);
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
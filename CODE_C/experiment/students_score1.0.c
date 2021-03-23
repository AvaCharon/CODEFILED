/***************
**学生成绩管理系统V1.0
**2020/10/28
杨骏飞
***************/

#include <stdio.h>
#include <stdlib.h>
#define N 30
void Input(int arr[],int arr2[],int n);
void TaA(int arr[],int n);
void Sort(int arr[],int arr2[], int (*compare)(int a,int b));
int Dorder(int a,int b);
int Aorder(int a,int b);
void SortNum(int arr[],int arr2[]);
void SearchNum(int arr[],int arr2[],int i);
void StatisticAnalysis(int arr[]);
int n,sum;

int main()
{
    int select;
    int stunumber[N],stuscore[N];
    while(1)
    {
        printf("1.Input record\n2.Calculate total and average score of course\n3.Sort in descending order by score\n");
        printf("4.Sort in ascending order by score\n5.Sort in ascending order by number\n6.Search by number\n");
        printf("7.Statistic analysis\n8.List record\n0.Exit\nPlease enter your choice:");
        scanf("%d",&select);
        switch(select)
        {
        case 1:
            printf("Input the total of the students:");
            scanf("%d",&n);
            Input(stuscore,stunumber,n);
            break;
        case 2:TaA(stuscore,n);break;
        case 3:Sort(stuscore,stunumber,Dorder);break;
        case 4:Sort(stuscore,stunumber,Aorder);break;
        case 5:SortNum(stuscore,stunumber);break;
        case 6:
            printf("Input the number you want to search:");
            int i;
            scanf("%d",&i);
            SearchNum(stunumber,stuscore,i);
            break;
        case 7:StatisticAnalysis(stuscore);break;
        case 8:
            for(int i=0;i<n;i++)
            {
                printf("%3d%3d",stunumber[i],stuscore[i]);
            }
            putchar('\n');
            TaA(stuscore,n);
            break;
        case 0:exit(0);
        }
    }
    return 0;
}


void Input(int arr[],int arr2[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Input the number of this student:");
        scanf(" %d",&arr2[i]);
        printf("Input the score of this student:");
        scanf(" %d",&arr[i]);
    }
    return;
}


void TaA(int arr[],int n)
{
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    printf("Sum=%d,average=%f\n",sum,((float)sum/n));
    return;
}

void Sort(int arr[],int arr2[], int (*compare)(int a,int b))
{
    for(int k=0;k<n;k++)
    {
        for(int j=k;j<n;j++)
        {
            if((*compare)(arr[k],arr[j]))
            {
                int i=arr[k];
                arr[k]=arr[j];
                arr[j]=i;
                i=arr2[k];
                arr2[k]=arr2[j];
                arr2[j]=i;
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d,%d\n",arr2[i],arr[i]);
    }
}

int Dorder(int a,int b)
{
    return a>b;
}

int Aorder(int a,int b)
{
    return a<b;
}

void SortNum(int arr[],int arr2[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr2[i]>arr2[j])
            {
                int temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d,%d\n",arr2[i],arr[i]);
    }
    return;
}

void SearchNum(int arr2[],int arr[],int i)
{
    int j;
    while(i!=arr2[j])
    {
        j++;
    }
    printf("%d\n",arr[j]);
    return;
}

void StatisticAnalysis(int arr[])
{
    int aGrade[5];
    for(int i=0;i<5;i++)
    {
        aGrade[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=90){aGrade[0]++;}
        else if(arr[i]>=80){aGrade[1]++;}
        else if(arr[i]>=70){aGrade[2]++;}
        else if(arr[i]>=60){aGrade[3]++;}
        else {aGrade[4]++;}
    }
    for(int j=0;j<5;j++)
    {
        printf("Grade %c:%d,%.3f%%\n",'A'+j,aGrade[j],((float)aGrade[j]/n)*100);
    }
    return;
}

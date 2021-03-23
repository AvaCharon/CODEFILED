/***************
**学生成绩管理系统V2.0
**2020/10/28
杨骏飞
***************/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 30//学生人数上限
#define S 2//学生学号与成绩上限
#define Name 20
void Input(int arr[][S],char str[][Name],int n);//确定人数，输入学号成绩姓名
void TaA(int arr[][S],int n);
void Sort(int arr[][S],char str[][Name] ,int (*compare)(int a,int b));//对成绩排序
int Dorder(int a,int b);
int Aorder(int a,int b);
void Dictionary(char str[][Name],int arr[][S]);
void SortNum(int arr[][S],char str[][Name]);
void SearchNum(int arr[][S],char str[][Name],int i);
void SearchName(int arr[][S],char str[][Name],char ch[Name]);
void StatisticAnalysis(int arr[][S]);
int n,sum;

int main()
{
    int select;
    int stu[N][S];
    char stuname[N][Name];
    while(1)
    {
        printf("*********************************************\n");
        printf("1.Input record\n2.Calculate total and average score of course\n3.Sort in descending order by score\n");
        printf("4.Sort in ascending order by score\n5.Sort in ascending order by number\n6.Sort in dictionary order by name\n7.Search by number\n");
        printf("8.search by name\n9.Statistic analysis\n10.List record\n11.Exit\nPlease enter your choice:");
        scanf("%d",&select);
        switch(select)
        {
        case 1:
            printf("Input the total of the students:");
            scanf("%d",&n);
            Input(stu,stuname,n);
            break;
        case 2:TaA(stu,n);break;
        case 3:Sort(stu,stuname,Dorder);
        for(int i=0;i<n;i++)
        {
            printf("学号：%d\t姓名：%s\t成绩：%d\n",stu[i][0],stuname[i],stu[i][1]);
        }
        break;
        case 4:Sort(stu,stuname,Aorder);
        for(int i=0;i<n;i++)
        {
            printf("学号：%d\t姓名：%s\t成绩：%d\n",stu[i][0],stuname[i],stu[i][1]);
        }
    break;
        case 5:SortNum(stu,stuname);break;
        case 6:Dictionary(stuname,stu);break;
        case 7:
            printf("Input the number you want to search:");
            int i;
            scanf("%d",&i);
            SearchNum(stu,stuname,i);
            break;
        case 8:
            printf("Input the name you want to search:");
            char stemp[Name];
            scanf("%s",stemp);
            SearchName(stu,stuname,stemp);
            break;
        case 9:StatisticAnalysis(stu);break;
        case 10:
            for(int i=0;i<n;i++)
            {
                printf("学号：%d，姓名：%s，成绩：%d\n",stu[i][0],stuname[i],stu[i][1]);
                int sums=0;
                for(int j=1;j<S;j++)
                {
                    sums=sums+stu[i][j];
                }
                printf("总分:%d\t平均分:%f\n",sums,((float)sums/(S-1)));
            }
            putchar('\n');
            break;
        case 11:exit(0);
        }
    }
    return 0;
}


void Input(int arr[][S],char arr2[][Name],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Input the number of this student:");
        scanf(" %d",&arr[i][0]);
        printf("Input the name of this student:");
        getchar();
        fgets(arr2[i],sizeof(arr2[i]),stdin);
        printf("Input the score of this student:");
        scanf(" %d",&arr[i][1]);
    }
    return;
}


void TaA(int arr[][S],int n)
{
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i][1];
    }
    printf("Sum=%d,average=%f\n",sum,((float)sum/n));
    return;
}

void Sort(int arr[][S],char str[][Name], int (*compare)(int a,int b))
{
    char ctemp[Name]={'\0'};
    for(int k=0;k<n;k++)
    {
        for(int j=k;j<n;j++)
        {
            if((*compare)(arr[k][1],arr[j][1]))
            {
                int i=arr[k][0];
                arr[k][0]=arr[j][0];
                arr[j][0]=i;
                i=arr[k][1];
                arr[k][1]=arr[j][1];
                arr[j][1]=i;
                strcpy(ctemp,str[k]);
                strcpy(str[k],str[j]);
                strcpy(str[j],ctemp);
            }

        }
    }
    return;
}

int Dorder(int a,int b)
{
    return a>b;
}

int Aorder(int a,int b)
{
    return a<b;
}

void Dictionary(char str[][Name],int arr[][S])
{
    for(int i=0;i<n;i++)
    {
        char ctemp[Name]={'\0'};
        int itemp=0;
        for(int j=i;j<n;j++)
        {
        if(strcmp(str[i],str[j])>0)
        {
            strcpy(ctemp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],ctemp);
            itemp=arr[i][0];
            arr[i][0]=arr[j][0];
            arr[j][0]=itemp;
            itemp=arr[i][1];
            arr[i][1]=arr[j][1];
            arr[j][1]=itemp;
        }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("学号：%d\t姓名：%s\t成绩：%d\n",arr[i][0],str[i],arr[i][1]);
    }
    return;
}

void SortNum(int arr[][S],char str[][Name])
{
    char ctemp[Name];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i][0]>arr[j][0])
            {
                int temp=arr[i][0];
                arr[i][0]=arr[j][0];
                arr[j][0]=temp;
                temp=arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=temp;
                strcpy(ctemp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],ctemp);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("学号：%d,姓名：%s，成绩：%d\n",arr[i][0],str[i],arr[i][1]);
    }
    return;
}

void SearchNum(int arr[][S],char str[][Name],int i)
{
    Sort(arr,str,Aorder);
    int j;
    while(i!=arr[j][0])
    {
        j++;
    }
    printf("学号:%d\t姓名:%s\t排名：%d\t成绩：%d\n",arr[j][0],str[j],j+1,arr[j][1]);
    return;
}

void SearchName(int arr[][S],char str[][Name],char ch[Name])
{
    Sort(arr,str,Aorder);
    for(int i=0;i<n;i++)
    {
        if(strcmp(ch,str[i])==0)
        {
            printf("学号：%d\t姓名：%s\t排名：%d\t成绩：%d\n",arr[i][0],str[i],i+1,arr[i][1]);
        }
    }
    return;
}

void StatisticAnalysis(int arr[][S])
{
    int aGrade[5];
    for(int i=0;i<5;i++)
    {
        aGrade[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][1]>=90){aGrade[0]++;}
        else if(arr[i][1]>=80){aGrade[1]++;}
        else if(arr[i][1]>=70){aGrade[2]++;}
        else if(arr[i][1]>=60){aGrade[3]++;}
        else {aGrade[4]++;}
    }
    for(int j=0;j<5;j++)
    {
        printf("Grade %c:%d,%.3f%%\n",'A'+j,aGrade[j],((float)aGrade[j]/n)*100);
    }
    return;
}

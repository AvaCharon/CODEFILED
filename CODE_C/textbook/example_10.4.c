#include<stdio.h>
#include<string.h>
#define Maxlen 10
#define N 150

void Sortstring(char str[][Maxlen],int n);//对字符串进行按字母排序

int main(void)
{
    int n;
    char name[N][Maxlen];
    printf("Input the number of the country:");
    scanf("%d",&n);
    getchar();
    printf("Input their names :\n");
    for(int i=0;i<n;i++)
    {
        gets(name[i]);
    }
    Sortstring(name,n);
    for(int i=0;i<n;i++)
    {
        puts(name[i]);
    }
    return 0;
}

void Sortstring(char str[][Maxlen],int n)
{
    char temp[Maxlen];
    int i;
    do//冒泡法
    {
        i=0;
        for(int j=0;j<n-1;j++)
        {
            if(strcmp(str[j+1],str[j])<0)
            {
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
                i++;
            }
        }
    } while (i>0);
    
}
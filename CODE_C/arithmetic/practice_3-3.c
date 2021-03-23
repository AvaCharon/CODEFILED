#include<stdio.h>
#include<string.h>
#define maxn 100
int main(void)
{
    int arr[maxn];
    memset(arr,-1,sizeof(arr));
    int num[10];
    memset(num,0,sizeof(num));
    for(int i=0;(arr[i]=getchar()-'0')!=-38;i++)//'\n'-'0'=-38
    {
        switch (arr[i])
        {
        case 1:num[1]++;break;
        case 2:num[2]++;break;
        case 3:num[3]++;break;
        case 4:num[4]++;break;
        case 5:num[5]++;break;
        case 6:num[6]++;break;
        case 7:num[7]++;break;
        case 8:num[8]++;break;
        case 9:num[9]++;break;
        case 0:num[0]++;break;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d\t",num[i]);
    }
    return 0;
}
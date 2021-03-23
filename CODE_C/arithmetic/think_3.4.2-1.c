#include<stdio.h>
//统计个数
/*
int main(void)
{
    int n,c=0;
    while (scanf("%d",&n)==1&&n!='\0')//enter ctrl+z enter 结束输入
    {
        c++;
    }
    printf("%d",c);
    return 0;
}
*/

#include<string.h>
#define maxn 1010
int main(void)
{
    int arr[maxn];
    memset(arr,0,maxn);
    int i=0;
    int n;
    scanf("%d",&n);
    int compare[n-1];
    memset(compare,0,n-1);
    for(;i<n;i++)scanf("%d",&arr[i]);
    for(int j=0;j<i;j++)//插入排序
    {
        int temp;
        int k=j;
        do
        {
            if(arr[k+1]>arr[k])
            {
                temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
                k--;
            }
        } while (arr[k+1]>arr[k]&&k!=-1);
    }
    for(int j=0;j<i-1;j++)
    {
        compare[j]=arr[j]-arr[j+1];
    }
    //快速排序
    /*
    int num=0;
    do
    {
        num=0;
        for(int j=0;j<sizeof(compare);j++)
        {
            int temp;
            if(compare[j+1]<compare[j])
            {
                temp=compare[j];
                compare[j]=compare[j+1];
                compare[j+1]=temp;
                num++;
            }
        }
    } while (num==0);
    */
    int min=0;
    int j;
    for(j=0;j<n-1;j++)
    {
        if(compare[0]>compare[j])
        {
            compare[0]=compare[j];
            min=j;
        }
    }
    printf("%d %d",arr[min],arr[min+1]);
    return 0;
}
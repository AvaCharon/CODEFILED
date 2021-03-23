#include<stdio.h>
int main(void)
{
    int n,a;
    scanf("%d",&n);
    int arr[n][4];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&arr[i][j]);
            getchar();
        }
    }
    for(int i=0;i<4;i++)//找出不同数
    {
        for(int j=0;j<n;j++)
        {
            if(arr[0][i]!=arr[j][i])
            {
                a=i;
            }
        }
    }
    for(int i=0;i<n;i++)//从不同数开始升序排列
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i][a]>arr[j][a])
            {
                int temp=arr[i][a];
                arr[i][a]=arr[j][a];
                arr[j][a]=temp;
            }
        }
    }
    int x=arr[0][a]^arr[n-1][a];
    int count=-1;
    while (x)
    {
        x>>=1;
        count++;
    }//找到不同位count
    int temp=arr[0][a];
    int p0=1;//找不同位后的最大为零位
    while (temp&&(count))
    {
        temp>>=1;
        count--;
        p0++;
    }
    char c=1;
    for(int i=1;i<p0;i++)
    {
        c=(c<<1)+1;//位运算符的优先度低于加减
    }
    c=~c;//使c的后p0位全为0
    unsigned int str[4];//ip
    unsigned int str2[4];//子网掩码
    str[a]=arr[0][a]&c;
    str2[a]=255&c;
    for(int i=0;i<a;i++)
    {
        str[i]=arr[0][i];
        str2[i]=255;
    }
    for(int i=a+1;i<4;i++)
    {
        str[i]=0;
        str2[i]=0;
    }
    for(int i=0;i<4;i++)
    {
        printf("%u.",str[i]);
    }
    for(int i=0;i<4;i++)
    {
        printf("%u.",str2[i]);
    }
    return 0;
}









/*
#include<stdio.h>
int main(void)
{
    //确定ip地址的相同项
    //算出子网掩码
    int n,a;
    char ch;
    scanf("%d",&n);
    int arr[n][4];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;)
        {
        if((ch=getchar())=='.')j++;
        scanf("%s",&arr[i][j]);
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[0][i]!=arr[j][i])
            {
                a=i;
                goto differ;
            }
        }
    }
    differ:
    for(int k=a;k<4;k++)//将从不同项开始的项从小到大排列
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(arr[i][k]>arr[j][k])
                {
                    int temp=arr[i][k];
                    arr[i][k]=arr[j][k];
                    arr[j][k]=temp;
                }
            }
        }
    }
    int min,max;//将从最小值的不同位a开始往后，第一个零后全为零


    return 0;
}
    
    /*
    for(int i=a;i<4;i++)
    {
        min=0,max=0;
        min=min+trantentwo(arr[0][i])*pow(10,8*(4-i));
        max=max+trantentwo(arr[n][i])*pow(10,8*(4-i));
    }
    for(int i=0;;i++)
    {
        int cha=max-min;
        if(cha<pow(10,1+i)&&cha>pow(10,i))
        {
            int k=i%8;
            
            break;
        }
    }
    if(arr[0][4]%2!=0)arr[0][4]--;

    return 0;
}


int trantentwo(int a)
{
    int b[100]={0},c;
    for(int i=0;i<100&&a>0;i++)
    {
        b[i]=a%2;
        a=a/2;
    }
    int k;
    for(int i=99;i>=0;i--)
    {
        if(b[i]!=0)
        {
            k=i;
            break;
        }
    }
    for(int i=0;i<100;i++)
    {
        c=c+b[i]*pow(10,i);
    }
    return c;
}
*/
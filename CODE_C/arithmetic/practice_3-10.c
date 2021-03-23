#include<stdio.h>
#include<string.h>
//fail
/*
int main(void)
{
    int str[6][2];
    memset(str,0,sizeof(str));
    int Find=0;
    int a,b,c,z=0;
    int num=1;
    for(int i=0;i<6;i++)
    {
        scanf("%d %d",&str[i][0],&str[i][1]);
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(i!=j&&str[i][0]==str[j][0]&&str[i][1]==str[j][1])
            {
                if(num==1)
                {
                    a=str[i][0];
                    b=str[i][1];
                    num++;
                }
                if(num==2)
                {
                    if(str[i][0]==a)
                    {
                        if(str[i][1]==b)z=1;
                        else
                        {
                            c=str[i][1];
                        }
                        num++;
                    }
                    else
                    {
                        if(str[i][1]!=a)Find--;
                        if(str[i][0]==b)z=1;
                        else
                        {
                            c=str[i][0];
                        }
                        num++;
                    }
                }
                if(num==3)
                {
                    if(z==1)
                    {
                        if(str[i][0]!=b||str[i][1]!=b)Find--;
                    }
                    else
                    {
                        if((str[i][0]!=a||str[i][1]!=b)&&(str[i][0]!=b||str[i][1]!=a))Find--;
                    }
                    
                }
                str[i][0]=-i;
                str[j][0]=-j;
                Find++;
                break;
            }
        }
    }
    if(Find==3)printf("Yes!\n");
    else
    {
        printf("No!\n");
    }
    return 0;
}
*/

int main(void)
{
    int s[6][2];
    for(int i=0;i<6;i++)
    {
        scanf("%d %d",&s[i][0],&s[i][1]);
        if(s[i][0]>s[i][1])
        {
            int temp;
            temp=s[i][0];
            s[i][0]=s[i][1];
            s[i][1]=temp;
        }
    }
    for(int i=0;i<6;i++)
    {
        for(int j=i;j<6;j++)
        {
            int temp;
            if(s[i][0]>s[j][0])
            {
                temp=s[i][0];
                s[i][0]=s[j][0];
                s[j][0]=temp;
            }
            else if(s[i][0]==s[j][0])
            {
                if(s[i][1]>s[j][1])
                {
                    temp=s[i][1];
                    s[i][1]=s[j][1];
                    s[j][1]=temp;
                }
            }
        }
    }
    int find1=1,find2=1,find3=0;
    for(int i=0;i<5;i=i+2)
    {
        if(s[i][0]!=s[i+1][0])find1=0;
        if(s[i][1]!=s[i+1][1])find2=0;
    }
    if(find1&&find2)
    {
        if(s[0][0]==s[2][0]&&s[2][1]==s[4][1]&&s[0][1]==s[4][0])find3=1;
        else if(s[0][0]==s[2][0]&&s[2][1]==s[4][0]&&s[0][1]==s[4][1])find3=1;
    }
    if(find2&&find1&&find3)printf("Yes!\n");
    else printf("No!\n");
    return 0;
}
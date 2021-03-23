#include<stdio.h>
#include<string.h>
/*
void removeKdigits(char * num, int k)
{
    int len=strlen(num);
    int num[len];
    for(int i=0;i<len;i++)
    {
        num[i]=num[i]-'0';
    }
    int start=0;
    for(int i=0;i<k;i++)
    {
    for(int j=start;j<len;j++)
    {
        if(j==len-1)
        {
            num[j]=0;
            len--;
            break;
        }

        if(j==start)
        {
        int p=1;
        if(!num[p])do
        {
            p++;
        } while (num[p]);
        if(num[0]>num[p])
        {
            num[0]=0;
            start++;
            break;
        }
        continue;
        }

        int p2=j-1;
        if(!num[p2])do
        {
            p2--;
        } while (num[p2]);
        int p3=j+1;
        if(!num[p3])do
        {
            p3++;
        } while (num[p3]);
        if((num[j]>num[p2])&&(num[j]>=num[p3]))
        {
            num[j]=0;
            for(int a=j;a<len-1;a++)
            {
                num[a]=num[a+1];
            }
            len--;
            break;
        }
    }
    }
    if(!(len-start))printf("0");
    start--;
    do
        {
            start++;
        } while (!num[start]);
    for(int i=start;i<len;i++)
    {
    printf("%d",num[i]);
    }
    return ;
}
int main(void)
{
    char num[10002];
    int k;
    scanf("%s%d",num,&k);
    removeKdigits(num,k);
    return 0;
}
*/


//
#include<string.h>
#include<malloc.h>
#include<stdio.h>
char * removeKdigits(char * num, int k)
{
    int len=strlen(num);
    int start=0;
    for(int i=0;i<k;i++)
    {
    for(int j=start;j<len;j++)
    {
        if(j==len-1)
        {
            num[j]=0;
            len--;
            break;
        }

        if(j==start)
        {
        int p=start+1;
        if(!num[p])do
        {
            p++;
        } while (num[p]);
        if(num[j]>num[p])
        {
            num[j]=0;
            start++;
            break;
        }
        continue;
        }

        int p2=j-1;
        if(!num[p2])do
        {
            p2--;
        } while (num[p2]&&(p2!=start));
        int p3=j+1;
        if(!num[p3])do
        {
            p3++;
        } while (num[p3]&&(p3!=(start+len)));
        if((num[j]>num[p2])&&(num[j]>=num[p3]))
        {
            num[j]=0;
            for(int a=j;a<len-1;a++)
            {
                num[a]=num[a+1];
            }
            len--;
            break;
        }
    }
    }
    int newlen=len-start;
    if(newlen==0)
    {
        char newnum[100];
        newnum[0]='0';
        newnum[1]=0;
        char *pt=newnum;
        return pt;
    }
    int newstart=start;
    if(num[newstart]=='0')
    {
        newstart--;
    do
        {

            newstart++;

        } while ((newstart<len)&&(num[newstart]=='0'));
    }
    newlen=len-newstart;
        if(newlen==0)
    {
        char newnum[100];
        newnum[0]='0';
        newnum[1]=0;
        char *pt=newnum;
        return pt;
    }
    char newn[newlen+1];
    newn[newlen]='\0';
    char *ptt=newn;
    for(int i=newstart,j=0;i<len;i++,j++)
    {
        newn[j]=num[i];
    }
    return ptt;
}


int main(void)
{
    char a[8]="4321";
    char *p=removeKdigits(a,2);
    printf("%s",p);
}

//

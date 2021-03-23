#include<stdio.h>
#include<string.h>
int main(void)
{
    int m,result=0,n;
    scanf("%d%d",&m,&n);
    char DNA[m][n+1];
    int Hammingsum[m];
    memset(Hammingsum,0,sizeof(Hammingsum));
    for(int i=0;i<m;i++)
    {
        scanf("%s",DNA[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(DNA[i][k]!=DNA[j][k])Hammingsum[i]++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(Hammingsum[0]>Hammingsum[i])
        {
            Hammingsum[0]=Hammingsum[i];
            result=i;
        }
        else if(Hammingsum[0]==Hammingsum[i])
        {
            if(strcmp(DNA[0],DNA[i])>0)
            {
                Hammingsum[0]=Hammingsum[i];
                result=i;
            }
        }
    }
    printf("%s\t%d",DNA[result],Hammingsum[0]);
    return 0;
}
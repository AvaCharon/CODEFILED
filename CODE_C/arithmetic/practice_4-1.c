/*****************
 * 象棋
 * 输入：所有棋子位置（保证红方已经将军）(2<=红方棋子数<=7)
 * 判断红方是否已经获胜
 * 将(J)、帅(G)、车(R)、马(H)、炮(C)
***************/
#include<stdio.h>
void Puton();//输入棋子位置
void Find(int i,int j);//寻找黑将在（i，j）时的下一步可选，坐标储存在opt[][]中,可选标记为1，否则为零
int Judge(int i,int j);//判断黑将在（i，j）时是否将军,是则返回1
char qipan[10][9];//棋盘
int opt[3][3];
int n,ji,jj;

int main(void)
{
    char select[10];
    int result;
    while(1)
    {
    scanf("%d%d%d",&n,&ji,&jj);
    if((n+ji+jj)==0)return 0;
    Puton;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(opt[i][j])
            {
                result=0;
                if(Judge(i,j+3))result=1;
            }
        }
    }
    if(result)printf("Yes!\n");
    else
    {
        printf("No.\n");
    }
    scanf("%s",select);
    }
    return 0;
}

void Puton()
{
    char ch;
    int i,j;
    for(int p=0;p<n;p++)
    {
        getchar();
        scanf("%c%d%d",&ch,&i,&j);
        qipan[i-1][j-1]=ch;
    }
    Find(ji-1,jj-4);
    return;
}

void Find(int i,int j)
{
    if(i!=2)
    {
        opt[i+1][j]=1;
    }
    if(i!=0)
    {
        opt[i-1][j]=1;
    }
    if(j!=2)
    {
        opt[i][j+1]=1;
    }
    if(j!=0)
    {
        opt[i][j-1]=1;
    }
    return;
}

int Judge(int i,int j)
{
    //帅(G)
    if(qipan[9][j]=='G'||qipan[8][j]=='G'||qipan[7][j]=='G')return 1;
    
    //车(R)
    for(int k=0;k<9;k++)//判断车是否在同一行,车与将之间是否有棋子阻挡
    {
        int find=1;
        if(qipan[k][j]=='R')
        {
            if(k>i)
            {
                for(int p=i;p<k;p++)
                {
                    if(qipan[p][j]!='0')find=0;
                }
            }
            if(k<i)
            {
                for(int p=k;p<i;p++)
                {
                    if(qipan[p][j]!='0')find=0;
                }
            }
            if(find==1)return 1;
        }
    }
    for(int k=0;k<10;k++)//判断车是否在同一列,车与将之间是否有棋子阻挡
    {
        int find=1;
        if(qipan[i][k]=='R')
        {
            if(k>j)
            {
                for(int p=j;p<k;p++)
                {
                    if(qipan[i][p]!='0')find=0;
                }
            }
            if(k<j)
            {
                for(int p=k;p<i;p++)
                {
                    if(qipan[i][p]!='0')find=0;
                }
            }
            if(find==1)return 1;
        }
    }

    //马(H)
    if(qipan[i+1][j+2]=='H'&&qipan[i+1][j+1]!='\0')return 1;
    if(qipan[i+1][j-2]=='H'&&qipan[i+1][j-1]!='\0')return 1;
    if(qipan[i+2][j+1]=='H'&&qipan[i+1][j+1]!='\0')return 1;
    if(qipan[i+2][j-1]=='H'&&qipan[i+1][j-1]!='\0')return 1;
    if(i!=0)
    {
        if(qipan[i-1][j-2]=='H'&&qipan[i-1][j-1]!='\0')return 1;
        if(qipan[i-1][j+2]=='H'&&qipan[i-1][j+1]!='\0')return 1;
        if(i==2)
        {
            if(qipan[0][j-1]=='H'&&qipan[1][j-1]!='\0')return 1;
            if(qipan[0][j+1]=='H'&&qipan[1][j+1]!='\0')return 1;
        }
    }
    
    //炮(C)
    for(int k=0;k<9;k++)
    {
        int num=0;
        if(qipan[i][k]=='C')
        {
            if(k<j)
            {
                for(int p=k;p<j;p++)
                {
                    if(qipan[i][p]!='\0')num++;
                }
                if(num==1)return 1;
            }
            if(k>j)
            {
                for(int p=j;p<k;p++)
                {
                    if(qipan[i][p]!='\0')num++;
                }
                if(num==1)return 1;
            }
        }
    }
    for(int k=0;k<10;k++)
    {
        int num=0;
        if(qipan[k][j]=='C')
        {
            if(k<i)
            {
                for(int p=k;p<i;p++)
                {
                    if(qipan[i][p]!='\0')num++;
                }
                if(num==1)return 1;
            }   
            if(k>i)
            {
                for(int p=i;p<k;p++)
                {
                    if(qipan[i][p]!='\0')num++;
                }
                if(num==1)return 1;
            }
        }
    }
    return 0;
}




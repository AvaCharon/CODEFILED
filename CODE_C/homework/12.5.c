#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct card 
{
    char face[10];
    char suit[10];
}Card;
int main(void)
{
    Card card[52];
    char Face[10]={'\0'};
    char Suit[10]={'\0'};
    for(int i=1;i<=4;i++)
    {
        if(i==1)strcpy(Face,"Spades");
        else if(i==2)strcpy(Face,"Heart");
        else if(i==3)strcpy(Face,"Clubs");
        else if(i==4)strcpy(Face,"Diamonds");
        for(int j=1;j<=13;j++)
        {
            if(j>1&&j<10)
            {
                strcpy(card[(i-1)*13+j-1].face,Face);
                card[(i-1)*13+j-1].suit[0]=j+'0';
                card[(i-1)*13+j-1].suit[1]='\0';
                continue;
            }
            else if(j==10)
            {
                strcpy(card[(i-1)*13+j-1].face,Face);
                card[(i-1)*13+j-1].suit[0]=1+'0';
                card[(i-1)*13+j-1].suit[1]=0+'0';
                card[(i-1)*13+j-1].suit[2]='\0';
                continue;
            }
            else if(j==1)strcpy(Suit,"A");
            else if(j==11)strcpy(Suit,"Jack");
            else if(j==12)strcpy(Suit,"Queen");
            else if(j==13)strcpy(Suit,"King");
            strcpy(card[(i-1)*13+j-1].face,Face);
            strcpy(card[(i-1)*13+j-1].suit,Suit);
        }
    }

    int c[52];
    for(int j=0;j<52;j++)
    {
        c[j]=j;
    }
    for(int i=0;i<52;i++)
    {
        srand(time(NULL));
        int j=rand()%(52-i)+i;
        int temp=c[i];
        c[i]=c[j];
        c[j]=temp;
    }
    for(int i=0;i<52;i++)
    {
        int j=c[i];
        printf("%s\t%s\n",card[j].face,card[j].suit);
    }

    /*
        for(int i=0;i<100;i++)
    {
        srand(time(NULL));//错误原因，时间过短没有刷新种子
        //解决方法：Sleep(100)
        int j=rand()%36;
        int temp=c[j];
        c[j]=c[j+16];
        c[j+16]=temp;
    }
    */



    /*
    for(int i=0;i<52;i++)
    {
        int last[52];
        int find,j;
        do
        {
        srand(time(NULL));
        j=rand()%52;
        find=0;
        for(int k=0;k<i;k++)
        {
            if(last[k]==j){find=1;break;}
        }
        }while(find);
        last[i]=j;
        printf("%s\t%s\n",card[j].face,card[j].suit);
    }
    */
    /*
    for(int i=0;i<52;i++)
    {
        printf("%s\t%s\n",card[i].face,card[i].suit);
    }
    */
    /*
    for(int i=0;i<52;i++)
        {
            if(((i+1)%13)==1||(i+1)%13==0||((i+1)%13)>10)printf("%s\t%s\n",card[i].face,card[i].suit);
            else printf("%s\t%d\n",card[i].face,card[i].suit[0]);
        }
    */
    return 0;
}
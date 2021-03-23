#include<stdio.h>
#include<string.h>
#define maxn 40
int win,lose;
int chance,left;
char strg[maxn],strc[maxn],ch;
void getastr(char str[]);
void guess(void);
int main(void)
{
    int n=0;
    while (scanf("%d",&n))
    {
        win=lose=0;
        n++;
        printf("Round %d.\n",n);
        getastr(strc);
        left=strlen(strc);
        guess();
        if(win)printf("You win.\n");
        else if(lose)printf("You lose.\n");
    }
    printf("You chickened out.\n");
    return 0;
}

void getastr(char str[])
{
    printf("Input a word:");
    scanf("%s",strc);
    return;
}

void guess()
{
    chance=7;
    do
    {
        printf("Input:");
        scanf(" %c",&ch);
        chance--;
        for(int i=0;i<strlen(strc);i++)
        {
            if(strc[i]==ch)
            {
                left--;
                strg[i]=ch;
            }
        }
        printf("%s\nAnd your still have %d chances.\n",strg,chance);
        if(!chance)lose=1;
        if(!left)win=1;
    } while (chance&&!win&&!lose);
}
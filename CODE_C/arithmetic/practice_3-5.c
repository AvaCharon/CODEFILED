#include<stdio.h>
int main(void)
{
    char str[5][5]={"TRGSJ","XDOKI","M\0VLN","WPABE","UQHCF"};
    char c;
    int i=2,j=1;
    while((c=getchar())!='0')
    {
        if(c!='A'&&c!='B'&&c!='L'&&c!='R')printf("This puzzle has no final configuration.\n");
        switch (c)
        {
        case 'A':
            str[i][j]=str[i-1][j];
            str[--i][j]='\0';
            break;
        case 'B':
            str[i][j]=str[i+1][j];
            str[++i][j]='\0';
            break;
        case 'L':
            str[i][j]=str[i][j-1];
            str[i][--j]='\0';
            break;
        case 'R':
            str[i][j]=str[i][j+1];
            str[i][++j]='\0';
            break;
        }
    }
    for(int n=0;n<5;n++)
    {
        for(int k=0;k<5;k++)
        {
            printf("%c\t",str[n][k]);
        }
        putchar('\n');
    }
    return 0;
}
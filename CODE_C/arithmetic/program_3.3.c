#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,x,y,i=1;
    scanf("%d",&n);
    int a[n][n];
    x=-1;
    y=n-1;
    int k=n;
    do
    {
        for(x++;x<k;x++)
        {
            a[x][y]=i++;
        }   
        for(x--,y--;y>=(n-k);y--)
        {
            a[x][y]=i++;
        }
        for(y++,x--;x>=(n-k);x--)
        {
            a[x][y]=i++;
        }
        for(x++,y++;y<k-1;y++)
        {
            a[x][y]=i++;
        }
        y--;
        k--;
    } while (i<=n*n);
    for(int j=0;j<n;j++)
    {
        for(int p=0;p<n;p++)
        {
            printf("%d ",a[j][p]);
        }
        putchar('\n');
    }
    return 0;
}
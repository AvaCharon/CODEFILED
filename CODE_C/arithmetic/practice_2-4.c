#include<stdio.h>
int main(void)
{
    int n;
    long m;
    double sum;
    do
    {
        sum=0;
        if(scanf("%d%d",&n,&m)&&(n<m)&&(m<1e6))
        {
            for(int i=n;i<=m;i++)
            {
                sum=sum+((1/(double)i)*(1/(double)i));
            }
            printf("%.5lf\n",sum);
        }
    } while ((n!=0)||m!=0);
    return 0;
}
#include<stdio.h>
int main(void)
{
    int m,n,s=100,vw;
    float hw;
    scanf("%d%d",&n,&m);
    int h[m*n];
    for(int i=0;i<m*n;i++)
    {
        scanf(" %d",&h[i]);
    }
    scanf("%d",&vw);
    for(int i=0;i<m*n;i++)
    {
        for(int j=i;j<m*n;j++)
        {
            if(h[i]>h[j])
            {
                int temp=h[i];
                h[i]=h[j];
                h[j]=temp;
            }
        }
    }
    int k=1,hw0=h[0];
    for(int i=1;i<m*n;i++)
    {
        hw=(float)vw/(k*s)+hw0;
        if(hw>h[i])
        {
            vw=vw-s*k*(h[i]-h[i-1]);
            hw0=h[i];
            k++;
        }
        if(vw<=0)break;
    }
    printf("%.2f,%.2f%%\n",hw,(float)k/(n*m)*100);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(void)
{
    int m,n;
    printf("How many classes and how many students in a class?\n");
    scanf("%d%d",&m,&n);
    int *score=(int *)calloc(m*n,sizeof(int));
    if(score==NULL)
    {
        printf("No enough memory!\n");
        exit(1);
    }
    printf("Input the scores:");
    for(int i=0;i<m*n;i++)
    {
        scanf("%d",&*(score+i));
    }
    int max=*score,p=1;
    for(int i=1;i<m*n;i++)
    {
        if(max<*(score+i))
        {
            max=*(score+i);
            p=i+1;
        }
    }
    printf("The highest score is %d,the student is No.%d student from Class %d",max,p-(p/n)*n+1,p/n);
    free(score);
    return 0;
}
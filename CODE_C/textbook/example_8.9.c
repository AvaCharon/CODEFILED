#include<stdio.h>
#define N 40
int Inp(int str[],int n);

int main(void)
{
    int score[N];
    int n;
    printf("Input the number of students:");
    scanf("%d",&n);
    Inp(score,n);
    
    return 0;
}
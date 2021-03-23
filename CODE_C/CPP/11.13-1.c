#include<stdio.h>
#include<string.h>
char **put(char *string, int n)
{
    char *array[n+1];
    char **result=array;
    for(int i=0;i<n;i++)
    {
        array[i]=gets_s(string,n+1);
    }
    return result;
}

int main(void)
{
    char *string;
    gets_s(string,100);
    printf("%p",put(string,3));
    return 0;
}
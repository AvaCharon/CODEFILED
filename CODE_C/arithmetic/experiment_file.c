#include<stdio.h>

//重定向（不能同时读写
/*
1.
int main(void)
{
    int a,b,c;
    freopen("D:\\bc\\VC\\CODE_C\\arithmetic\\input.txt","r",stdin);//文件中数字不要用逗号隔开
    freopen("D:\\bc\\VC\\CODE_C\\arithmetic\\output.txt","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    printf("%d,%d,%d",a+1,b+1,c+1);
    return 0;
}

2.
int main(void)
{
    int a;
    freopen("input.txt","r",stdin);//找不到文件？？
    freopen("output.txt","w",stdout);
    return 0;
}
*/


//fopen（繁琐但灵活，可多次打开读写文件
//FILE *fopen(char *filename, char *mode);
/*
r(read)：读
w(write)：写
a(append)：追加
t(text)：文本文件
b(banary)：二进制文件
+：读和写
*/
#define N 100
int main(void)
{
    char str[N+1];
    FILE* fp=fopen("Input.txt","r+");
    while (fgets(str,N,fp)!=NULL)
    {
        printf("%s",str);
    }
    
    return 0;
}
/*
#define LOCAL
...
#ifdef LOCAL//条件编译命令
...
#endif
...
*/
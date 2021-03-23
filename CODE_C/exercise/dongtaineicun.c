/*
malloc =  memory allocate(分配)
*/

#include<stdio.h>
#include<malloc.h>//必需的头文件

int main(void)
{
    int i=5;//静态分配(本机4字节)
    int *p=(int *)malloc(4);//一个整数类型的形参表示分配的内存的字节数
                            //malloc函数返回第一个字节的地址
                            //注意，malloc函数返回的指针类型是void型
                            //void型指针可以被任意类型指针赋值，如:int* p;void* q;q=p;(合法)
                            //但void指针赋值给其他指针时必须使用强转，如本例 
                            //此时11行向系统要了8个字节，即p本身4个（静态），p作为指针指向的内存有4个字节（即整形变量*p占用的内存）（动态）
    free(p);//将p指向的内存(动态的那4个字节)释放
    printf("Hello!\n");
    
    return 0;
}

/*
calloc(size_t n,size_t size)//在内存中分配n个长度为size的连续空间
如
float*pf;
pf=(float*)calloc(10,sizeof(float))
注意，calloc在分配内存的同时将其初始化为零
*/

/*
realloc(void *p,unsigned int size)
把p所指向的内存空间变为size个字节
*/
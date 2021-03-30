#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 100
typedef int SElemType;
typedef int Status;

typedef struct 
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}mystack;

int Initmystack(mystack &S)
{
    S.base=(SElemType *)malloc(MAXSIZE * sizeof(SElemType));
    if(!S.base)exit(0);
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return 1;
}

int isEmpty(mystack &S)
{
    if(S.top==S.base)return 1;
    return 0;
}

int isFull(mystack &S)
{
    if(S.top-S.base==MAXSIZE)return 1;
    return 0;
}

int push(mystack &S,SElemType e)
{
    if(isFull(S))exit(0);
    *++S.top=e;
    return 1;
}

Status pop(mystack &S)
{
    if(isEmpty(S))exit(0);
    SElemType tmp=*S.top;
    S.top--;
    return tmp;
}




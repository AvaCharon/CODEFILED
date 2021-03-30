#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 100

typedef int QElemType;
typedef int Status;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePrt;

typedef struct{
    QElemType *base;
    int front;
    int rear;
}CircularQueue;

QElemType* InitCircularQueue(CircularQueue &q)
{
    q.base=(QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
    if(!q.base)exit(0);
    q.front=q.rear=0;
    return q.base;
}

int QueueLength(CircularQueue q)
{
    return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;
}

int isEmpty(CircularQueue q)
{
    if(q.rear==q.front)return 1;
    return 0;
}

int isFull(CircularQueue q)
{
    if((q.rear+1)%MAXQSIZE==q.front)return 1;
    return 0;
}

int EnQueue(CircularQueue &q,QElemType e)
{
    if(isFull(q))exit(0);
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return 1;
}

int DeQueue(CircularQueue &q)
{
    if(isEmpty(q))return 0;
    q.front=(q.front+1)%MAXQSIZE;
    return 1;
}
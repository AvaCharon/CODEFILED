#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;
typedef int Status;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePrt;

typedef struct{
    QueuePrt front;
    QueuePrt rear;
}LinkQueue;

QueuePrt InitQueue(LinkQueue &q)
{
    q.front=q.rear=(QueuePrt)malloc(sizeof(QNode));
    if(!q.front)exit(0);
    q.front->next=NULL;
    return q.front;
}

int DestroyQueue(LinkQueue &q)
{
    while (q.front)
    {
        q.rear=q.front->next;
        free(q.front);
        q.front=q.rear;
    }
    return 1;
}

int ClearQueue(LinkQueue &q)
{
    while (q.front)
    {
        q.front->data=0;
        q.front=q.front->next;
    }
    return 1;
}

int isEmpty(LinkQueue q)
{
    if(q.front==q.rear&&q.front->data==0)return 1;
    return 0;
}

int QueueLength(LinkQueue q)
{
    int ans=0;
    while (q.front)
    {
        ans++;
        q.front=q.front->next;
    }
    return ans;
}

int EnQueue(LinkQueue &q,QElemType &e)
{
    QueuePrt p=(QueuePrt)malloc(sizeof(QNode));
    if(!p)exit(0);
    p->data=e;
    p->next=NULL;
    q.rear->next=p;
    return 1;
}

int DeQueue(LinkQueue &q)
{
    if(isEmpty(q))exit(0);
    QueuePrt p=q.front->next;
    free(q.front);
    q.front=p;
    return 1;
}

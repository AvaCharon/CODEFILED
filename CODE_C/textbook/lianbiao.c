#include<stdio.h>
#include<stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *DeleteNode(struct link* head,int nodeData);
struct link
{
    int data;
    struct link *next;
};
int main(void)
{
    int i=0;
    char c;
    struct link*head =NULL;
    scanf("%c",&c);
    while(c=='y'||c=='Y')
    {
        head=AppendNode(head);
        scanf("%c",&c);
    }
    DeleteMemory(head);
    return 0;
}

struct link *AppendNode(struct link *head)
{
    struct link *p=NULL,*pr=head;
    int data;
    p = (struct link *)malloc(sizeof(struct link));
    if(p==NULL)
    {
        printf("No enough memory.\n");
        exit(0);
    }
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        while (pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next=p;
    }
    scanf("%d",&data);
    p->data=data;
    p->next=NULL;
    return head;
}

void DisplyNode(struct link *head)
{
    struct link *p=head;
    int j=1;
    while (p!=NULL)
    {
        printf("%5d%10d\n",j,p->data);
        p=p->next;
        j++;
    }
    return;
}

void DeleteMemory(struct link *head)
{
    struct link *p=head,*pr=NULL;
    while (p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);
    }
    return ;
}


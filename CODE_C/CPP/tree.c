#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

void InitializeTree(Tree *ptree)
{
    ptree->root=NULL;
    ptree->size=0;
    return;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if(ptree->root==NULL)return true;
    return false;
}

bool TreeIsFUll(const Tree *ptree)
{
    if(TreeItemCount(ptree)==ptree->size)return true;
    return false;
}

int TreeItemCount(const Tree *ptree)
{
    Trnode *nowl,*nowr;
    int countl=0,countr=0;
    nowl=nowr=ptree->root;
    while (nowl!=NULL)
    {
        nowl=nowl->left;
        countl++;
    }
    while (nowr!=NULL)
    {
        nowr=nowr->right;
        countr++;
    }
    return (countr+countl);
}

bool AddItem(const Item *pi,Tree *ptree)
{
    Trnode *newnode;
    if(TreeIsEmpty(ptree))
    {
        newnode=ptree->root;
        return true;
    }
    else if(TreeIsFUll(ptree))
    {
        printf("Tree is full!\n");
        return false;
    }
    else if(SeekItem(pi,ptree).child!=NULL)
    {
        fprintf(stderr,"Couldn't create node\n");
        return false;
    }
    newnode=MakeNode(pi);
    if(newnode==NULL)
    {
        fprintf(stderr,"Couldn't create node\n");
        return false;
    }
    ptree->size++;
    AddNode(newnode,ptree->root);
    return true;
}

static Trnode *MakeNode(const Item *pi)
{
    Trnode *newnode;
    newnode=(Trnode *)malloc(sizeof(Trnode));
    if(newnode!=NULL)
    {
        newnode->item=*pi;
        newnode->left=NULL;
        newnode->right=NULL;
    }
    return newnode;
}

static void AddNode(Trnode *newnode,Trnode *root)
{
    if(ToLeft(&newnode->item,&root->item))
    {
        if(root->left==NULL)
        root->left=newnode;
        else
        AddNode(newnode,root->left);
    }
    else if(ToRight(&newnode->item,&root->item))
    {
         if(root->right==NULL)
        root->right=newnode;
        else
        AddNode(newnode,root->right);
    }
    else
    {
        fprintf(stderr,"location error in AddNode()\n");
        exit(1);
    }
    return ;
}

static bool Toleft(const Item *i1,const Item *i2)
{
    int comp1;
    if((comp1=strcmp(i1->patname,i2->patname))<0)
    {
        return true;
    }
    else if(comp1==0&&strcmp(i1->petkind,i2->petkind)<0)
    {
        return true;
    }
    else return false;
}

static bool ToRight(const Item *i1,const Item *i2)
{
    int comp1;
    if((comp1=strcmp(i1->patname,i2->patname))>0)
    {
        return true;
    }
    else if(comp1==0&&strcmp(i1->petkind,i2->petkind)>0)
    {
        return true;
    }
    else return false;
}




typedef struct pair
{
    Trnode *parent;
    Trnode *child;
}Pair;

static Trnode *MakeNode(const Item *pi);

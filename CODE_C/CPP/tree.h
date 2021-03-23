#ifndef _TREE_H_


#define _TREE_H_
#include<stdbool.h>

#define SLEN 20
typedef struct item
{
    char patname[SLEN];
    char petkind[SLEN];
}Item;

#define MAXITEMS 10
typedef struct trnode
{
    Item item;
    struct trnode *left;
    struct trnode *right;
}Trnode;

typedef struct tree
{
    Trnode *root;
    int size;
}Tree;


void InitializeTree(Tree *ptree);//初始化树为空
bool TreeIsEmpty(const Tree *ptree);//判断树是否为空
bool TreeIsFull(const Tree *ptree);//判断树是否满
int TreeItemCount(const Tree *ptree);//确定树的项数
bool AddItem(const Item *pi,Tree *ptree);//添加项
bool InTree(const Item *pi,const Tree *ptree);//查找项
bool DeleteItem(const Item *pi,const Tree *ptree);//删除项
void Traverse(const Tree *ptree,void(*pfun)(Item item));//删除树
static Trnode *MakeNode(const Item *pi);//建立结点

#endif


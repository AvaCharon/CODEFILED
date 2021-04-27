#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
//无向图
//
typedef struct
{
    int edge[maxn][maxn]; //邻接矩阵
    int v;
    int e;
    bool vis[maxn];
} MyGraph_1;
MyGraph_1 *createMyGraph_1()
{
    int i;
    int j;
    int start;
    int end;
    MyGraph_1 *G = (MyGraph_1 *)malloc(sizeof(MyGraph_1));

    cout << "please input the ves and edge:" << endl;
    cin >> G->v >> G->e;
    //初始化
    for (i = 0; i < G->v; i++)
    {
        for (j = 0; j < G->v; j++)
        {
            G->edge[i][j] = 0;
        }
        G->vis[i] = 0; //标识全部置0,表示没有访问过结点
    }
    //创建邻接矩阵
    cout << "please input the edge(vi,vj)\n"
         << endl;
    for (i = 0; i < G->e; i++)
    {
        cin >> start >> end;
        G->edge[start][end] = 1;
    }
    return G;
}

//
typedef struct ENode
{
    int vi;
    ENode *next;
} ENode;
typedef struct VNode
{
    int value;
    ENode *first;
} VList[maxn];
typedef struct
{
    VList V; //vector<VNode> V; //邻接表
    int v;
    int e;
    bool vis[maxn];
} MyGraph_2;
MyGraph_2 *createMyGraph_2()
{
    int i;
    int start;
    int end;
    MyGraph_2 *G = (MyGraph_2 *)malloc(sizeof(MyGraph_2));
    ENode *e;
    cout << "please input the ves and edge:" << endl;
    cin >> G->v >> G->e;
    //初始化
    cout << "please input the ves:" << endl;

    for (i = 0; i < G->v; i++) //输入顶点
    {
        cin >> G->V[i].value;
        G->V[i].first = NULL;
    }
    //创建邻接矩阵
    cout << "please input the edges:" << endl;
    ;
    for (i = 0; i < G->e; i++)
    {
        cin >> start >> end;

        e = (ENode *)malloc(sizeof(ENode));
        e->vi = end;
        e->next = G->V[start].first;
        G->V[start].first = e; //类似于链表的前插

        e = (ENode *)malloc(sizeof(ENode));
        e->vi = start;
        e->next = G->V[end].first;
        G->V[end].first = e; //类似于链表的前插
    }
    return G;
}
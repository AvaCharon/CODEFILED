#include <bits/stdc++.h>
#include "graph.h"
using namespace std;
//2.1
void dfs(MyGraph_2 *a, int v)
{
    memset(a->vis, false, sizeof(a->vis));
    stack<int> st; //用栈模拟递归的过程
    st.push(v);
    printf("%d", v);
    a->vis[v] = true;

    //非递归dfs
    while (!st.empty())
    {
        int tmp = st.top();
        ENode *nextnode = a->V[tmp].first;
        while (nextnode != nullptr) //遍历当前结点连接的结点
        {
            if (!a->vis[nextnode->vi]) //若未访问则访问
            {
                printf("%d", nextnode->vi);
                st.push(nextnode->vi);
                a->vis[nextnode->vi] = true;
                nextnode = a->V[st.top()].first;
            }
            else
                nextnode = nextnode->next;
        }
        if (nextnode == nullptr) //表示当前结点无连接结点或连接的结点都已访问，回退
            st.pop();
    }
    return;
}

//2.2
bool EasyPath(MyGraph_2 *a, int u, int v)
{
    memset(a->vis, false, sizeof(a->vis));
    a->vis[u] = true;
    vector<int> ans; //用以存储路径上的结点
    ans.push_back(u);
    stack<int> st;
    st.push(u);

    //dfs找简单路径,具体过程类似于2.1
    while (!st.empty())
    {
        ENode *nextnode = a->V[st.top()].first;
        while (nextnode != nullptr)
        {
            if (!a->vis[nextnode->vi])
            {
                if (nextnode->vi == v) //到达终点，输出路径并结束函数
                {
                    ans.push_back(v);
                    for (int it : ans)
                        cout << it;
                    return true;
                }
                a->vis[nextnode->vi] = true;
                st.push(nextnode->vi);
                ans.push_back(nextnode->vi);
                nextnode = a->V[nextnode->vi].first;
            }
            else
                nextnode = nextnode->next;
        }
        if (nextnode == nullptr) //回退并将当前结点从路径上清除
        {
            st.pop();
            ans.pop_back();
        }
    }
    //当遍历结束未到达终点即不存在该简单路径
    return false;
}

//2.3
//将强盗结点及其相邻的边删掉（输入时删掉或在遍历时用if语句排除掉）
//将问题转化为：求从入口与食品、食品与财宝、财宝与出口或入口与财宝、食品与财宝、食品与出口之间的简单路径

int main()
{
    MyGraph_2 *G1 = createMyGraph_2();
    //dfs(G1, 0);
    //EasyPath(G1, 0, 7);
    return 0;
}
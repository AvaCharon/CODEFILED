//最优二叉搜索树
#include <bits/stdc++.h>

using namespace std;

/*struct BSTree
{
    int val;
    BSTree *left;
    BSTree *right;
    BSTree() : val(0), left(nullptr), right(nullptr) {}
};*/

//打印该最优二叉搜索树结构
void PrintOBST(vector<vector<int>> &root, int i, int j, int lenk)
{
    if (i == 1 && j == lenk)
        printf("K%d为根\n", root[i][j]);
    if (i < j)
    {
        printf("K%d是K%d的左孩子\n", root[i][root[i][j] - 1], root[i][j]);
        PrintOBST(root, i, root[i][j] - 1, lenk);
        if (root[i][j] + 1 < j) /* 注意这里的细节，不然会出现root[5][4]和root[6][5] */
            printf("K%d是K%d的右孩子\n", root[root[i][j] + 1][j], root[i][j]);
        /* else  cout<<root[i][j]+1<<"\t"<<j<<endl; */
        PrintOBST(root, root[i][j] + 1, j, lenk);
    }

    if (i == j)
    {
        printf("d%d是K%d的左孩子\n", i - 1, i);
        printf("d%d是K%d的右孩子\n", i, i);
    }
    if (i > j)
        printf("d%d是K%d的右孩子\n", j, j);
}

double OBST(vector<vector<int>> &dep, vector<int> &k, vector<int> &d, vector<double> &p, vector<double> &q)
{
    int lenk = k.size();
    double E[lenk + 2][lenk + 2];
    double W[lenk + 2][lenk + 2]; //W[i][j]=p[i]到p[j]+q[i-1]到q[j]

    for (int i = 1; i <= lenk; i++)
    {
        W[i][i - 1] = q[i - 1];
        E[i][i - 1] = q[i - 1];
    }

    for (int len = 1; len <= lenk; len++)
        for (int i = 1; i <= lenk - len + 1; i++)
        {
            int j = i + len - 1;
            E[i][j] = 1e6;
            W[i][j] = W[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++)
            {
                double temp = E[i][r - 1] + E[r + 1][j] + W[i][j];
                if (temp < E[i][j])
                {
                    E[i][j] = temp;
                    dep[i][j] = r;
                }
            }
        }
    PrintOBST(dep, 1, lenk, lenk);
    return E[1][lenk];
}

int main()
{
    vector<int> k = {1, 2, 3, 4, 5, 6, 7}, d = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<double> p = {0.04, 0.06, 0.08, 0.02, 0.1, 0.12, 0.14}, q = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
    vector<vector<int>> dep; //记录分割点
    int lenk = k.size();
    vector<int> tmp(lenk + 1);
    for (int i = 0; i <= lenk; i++)
    {
        dep.push_back(tmp);
    }
    cout << OBST(dep, k, d, p, q);
    return 0;
}
//2.1
int solution1(int i, int j) //利用下标特点找到公共祖先结点下标
{
    if (i == j)
        return i;
    else if (i < j)
        return solution1(i, j / 2);
    return solution1(i / 2, j);
}

//2.2
//时间复杂度O(n)
bool find = false;
void solution2(TreeNode *bt, int x) //dfs查找，找到就回溯
{
    if (!find && bt)
    {
        if (bt->val == x)
            find = true;
        if (!find)
        {
            solution2(bt->left);
        }
        if (!find)
        {
            solution2(bt->right);
        }
        if (find)
            printf("%d", bt->val);
    }
    return;
}

//2.3
int solution3(TreeNode *T)
{
    if (!T)
        return 0;
    int height = 1, width = 1;
    queue<root *> q;
    q.push(T);
    while (!q.empty()) //利用队列逐层遍历求最大宽度
    {
        int len = q.size();
        width = max(width, len);
        for (int i = 0; i < len; i++)
        {
            TreeNode *tmp = q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        height++;
    }
    return width * height;
}

//2.4
void deleteTree(TreeNode *T) //后序递归，删除以T为根的子树
{
    if (T)
    {
        deleteTree(T->left);
        deleteTree(T->right);
        delete T;
        T = nullptr;
    }
    return;
}
void solution4(TreeNode *T, int x)
{
    if (T) //前序递归遍历查找
    {
        if (T->val == x)
            deleteTree(T);
        else
        {
            solution4(T->left, x);
            solution4(T->right, x);
        }
    }
    return;
}
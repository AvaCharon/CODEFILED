#include <bits/stdc++.h>
using namespace std;

int f[20];
int n;

int main()
{
    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] += f[j] * f[i - j - 1];
        }
    }
    cout << f[n];
    return 0;
}

//

#include <bits/stdc++.h>
using namespace std;
int m;
int f[20][20]; //f[i][j]i代表操作队列中元素的个数，j代表栈中元素的个数，表示这种情况的总数

int dfs(int i, int j)
{
    if (f[i][j])
        return f[i][j]; //说明该种情况已经处理过
    if (i == 0)
        return 1; //此时说明操作队列中元素全部进入栈中，那么此时按照栈的输出规定，只能有一种情况
    if (j > 0)
        f[i][j] += dfs(i, j - 1); //输出栈顶元素，pop
    f[i][j] += dfs(i - 1, j + 1); //将操作序列最前面的数放入到栈中 ，push
    return f[i][j];
}

int main()
{
    scanf("%d", &m);
    printf("%d", dfs(m, 0));
    return 0;
}

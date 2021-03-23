#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, k;

struct num//记录位置与数字
{
    int order, val;
    num(int order = 0, int val = 0) : order(order), val(val){};
};
deque<num> maxnn;
deque<num> minnn;

int maxn[N], cnt = 0;
int main()
{
    scanf("%d%d", &n, &k);
    num temp;
    for (int i = 1; i <= n; ++i)
    {
        temp.order = i;
        scanf("%d", &temp.val);
        while (!maxnn.empty() && temp.val >= maxnn.back().val)//使最值保持在最前
            maxnn.pop_back();
        while (!minnn.empty() && temp.val <= minnn.back().val)
            minnn.pop_back();

        maxnn.push_back(temp);
        minnn.push_back(temp);

        while (!maxnn.empty() && i - maxnn.front().order >= k)
            maxnn.pop_front();
        while (!minnn.empty() && i - minnn.front().order >= k)
            minnn.pop_front();

        if (i >= k)
        {
            printf("%d ", minnn.front().val);
            maxn[++cnt] = maxnn.front().val;
        }
    }

    printf("\n");
    for (int i = 1; i <= cnt; ++i)
    {
        printf("%d ", maxn[i]);
    }
    return 0;
}

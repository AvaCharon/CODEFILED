#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n;
    cin >> k;
    vector<int> nums(n);
    nums[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        nums[i] = nums[i - 1] * i;
    }
    --k;
    int ans[n];
    int cnt = 0;
    vector<int> visit(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        int order = k / nums[n - i] + 1;
        for (int j = 1; j <= n; ++j)
        {
            order -= visit[j];
            if (!order)
            {
                ans[cnt++] = j;
                visit[j] = 0;
                break;
            }
        }
        k %= nums[n - i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (i < n - 1)
            cout << " ";
    }
    return 0;
}



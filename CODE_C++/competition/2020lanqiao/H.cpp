#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long ans = 0;
    cin >> s;
    int len = s.size();
    int prev[len + 1];
    int next[len + 1];
    memset(prev, 0, sizeof(prev));
    for (int i = 1; i <= len; i++)
        next[i] = len + 1;
    int pre[26]; //存储出现相同字母的下标
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= len; i++)
    {
        prev[i] = pre[s[i - 1] - 'a'];
        pre[s[i - 1] - 'a'] = i;
        next[prev[i]] = i;
    }
    for (int i = 1; i <= len; i++)
        ans += (i - prev[i]) * (next[i] - i);
    cout << ans;
    return 0;
}
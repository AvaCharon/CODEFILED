//匹配子串
#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

string s1, s2;
vector<int> ans;

int *getnext(string s2)
{
    int len = s2.size();
    int *next = new int[len];
    next[0] = -1;
    int j = 0, k = -1;
    while (j < len)
    {
        if (k == -1 || s2[j] == s2[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

void kmpsearch(string s1, string s2)
{
    int *next = getnext(s2);
    int i = 0, j = 0;
    int len1 = s1.size();
    int len2 = s2.size();
    for (int i = 0, j = 0; i < len1;)
    {
        while (i < len1 && j < len2)
        {
            if (j == -1 || s1[i] == s2[j])
            {
                i++, j++;
            }
            else
                j = next[j];
        }
        if (j == len2)
        {
            ans.push_back(i - len2);
            i -= len2 - 1;
            j = 0;
        }
    }
    return;
}

int main()
{
    cin >> s1 >> s2;
    kmpsearch(s1, s2);
    for (int it : ans)
        cout << it << endl;
    return 0;
}
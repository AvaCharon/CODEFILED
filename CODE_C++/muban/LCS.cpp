#include <bits/stdc++.h>

using namespace std;

int LCS(string s, string t)
{
    int lens = s.size();
    int lent = t.size();
    int dp[lens + 1][lent + 1];
    int B[lens + 1][lent + 1]; //0,1上,2左
    for (int i = 0; i < lens + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < lent + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= lens; i++)
    {
        for (int j = 1; j <= lent; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                B[i][j] = 0;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    B[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    B[i][j] = 2;
                }
            }
        }
    }

    int i = lens, j = lent;
    vector<char> output;
    do
    {
        while (i >= 0 && j >= 0 && (B[i][j] == 1 || B[i][j] == 2))
        {
            if (B[i][j] == 1)
                i--;
            else
                j--;
        }
        if (B[i][j] == 0)
        {
            output.emplace_back(s[i - 1]);
            i--, j--;
        }
    } while (i >= 1 && j >= 1);
    for (int i = output.size() - 1; i >= 0; i--)
        cout << output[i];

    return dp[lens][lent];
}

int main(void)
{
    string s = "asddsfadfaafggaf";
    string t = "asdgerargrgarg";
    cout << LCS(s, t);
    return 0;
}
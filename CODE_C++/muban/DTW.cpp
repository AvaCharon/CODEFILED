//动态时间规整
#include <bits/stdc++.h>

using namespace std;

int DTW(vector<int> &A, vector<int> &B)
{
    int lena = A.size();
    int lenb = B.size();
    int dis[lena][lenb];
    int dp[lena][lenb]; //dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+dis[i][j]

    for (int i = 0; i < lena; i++)
        for (int j = 0; j < lenb; j++)
            dis[i][j] = A[i] > B[j] ? A[i] - B[j] : B[j] - A[i];

    for (int i = 0; i < lena; i++)
    {
        for (int j = 0; j < lenb; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = dis[i][j];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + dis[i][j];
        }
    }
    return dp[lena - 1][lenb - 1];
}

int main()
{
    vector<int> A, B;
    cout << DTW(A, B);
    return 0;
}

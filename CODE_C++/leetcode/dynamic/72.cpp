//对A插入等价于对B删除，对A删除等价于对B插入
//f[i][j]表示从word1的前i个到word2的前j个的最短编辑距离
//f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1]+(int)(word1[i]!=word2[j]))
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int f[n+1][m+1];
        memset(f,0,sizeof(f));
        for(int i=0;i<=n;i++)
        {
            f[i][0]=i;
        }
        for(int j=0;j<=m;j++)
        {
            f[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                    f[i][j]=min(f[i-1][j]+1,min(f[i][j-1]+1,f[i-1][j-1]+(int)(word1[i-1]!=word2[j-1])));
            }
        }
        return f[n][m];
    }
};
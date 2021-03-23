class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)return 1;
        int f[m+1][n+1];
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1&&j==1)
                {
                    f[i][j]=1;
                    continue;
                }
                if(f[i][j]>=INT_MAX-f[i-1][j])return INT_MAX+1;
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        return f[m][n];
    }
};
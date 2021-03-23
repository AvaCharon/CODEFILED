class Solution {
public:
    int numTrees(int n) {
        if(n==0)return 0;
        int f[n+1],g[n+1][n+1];//f[j]j个数的最多 g[i][j]以i为根且总数为j的个数
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        f[0]=1;
        g[1][1]=1;
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=j;i++)
            {
                g[i][j]=f[i-1]*f[j-i];//左树*右树
                f[j]+=g[i][j];
            }
        }
        return f[n];
    }
};
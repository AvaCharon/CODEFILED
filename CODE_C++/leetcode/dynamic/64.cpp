class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.at(0).size();
        if(m==1&&n==1)return grid[0][0];
        int f[n+1][m+1];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1||j==1)
                {
                    if(i==j)
                    f[1][1]=grid[0][0];
                    else if(i==1)
                    {
                        f[i][j]=f[i][j-1]+grid[i-1][j-1];
                    }
                    else if(j==1)
                    {
                        f[i][j]=f[i-1][j]+grid[i-1][j-1];
                    }
                    continue;
                }
                f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i-1][j-1];
            }
        }
        return f[n][m];
    }
};
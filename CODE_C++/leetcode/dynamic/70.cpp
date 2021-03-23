class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int f[n+2];//第i阶楼梯的方法 f[i]=f[i-1]+f[i-2]
        f[1]=1,f[2]=2;
        for(int i=3;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
};
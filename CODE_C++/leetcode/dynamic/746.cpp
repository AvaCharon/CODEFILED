class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        int f[len+1];
        f[0]=cost[0];
        f[1]=cost[1];
        for(int i=2;i<len;i++)
        {
            f[i]=min(f[i-1],f[i-2])+cost[i];
        }
        return min(f[len-1],f[len-2]);
    }
};
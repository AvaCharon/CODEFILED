


//厄拉多塞筛法
class Solution {
public:
    int countPrimes(int n) {
        int signs[n+1];
        memset(signs,1,sizeof(signs));
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(signs[i])
            {
                count++;
                for(int j=2*i;j<n;j+=i)
                {
                    signs[j]=0;
                }
            }
        }
        return count;
    }
};
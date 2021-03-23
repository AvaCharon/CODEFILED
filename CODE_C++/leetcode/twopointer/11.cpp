class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxn=0;
        while (j>i)
        {
            if(height[i]<=height[j])
            {
                maxn=max(height[i]*(j-i),maxn);
                i++;
            }
            else
            {
                maxn=max(height[j]*(j-i),maxn);
                j--;
            }
        }
        return maxn;
    }
};
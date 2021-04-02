/*
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        int ans = 0;
        bool end = true;
        int minn = INT_MAX;
        while (1)
        {
            end = true;
            for (int i = 0; i < len;)
            {
                minn = INT_MAX;
                int tmp = 0;
                int left, right;
                while (i < len && !height[i])
                {
                    i++;
                }
                left = i;
                while (i < len && height[i])
                {
                    minn = min(minn, height[i]);
                    i++;
                }
                right = i - 1;
                for (int j = left; j <= right; j++)
                {
                    end = false;
                    height[j] -= minn;
                }
                while (i < len && !height[i])
                {
                    tmp++;
                    i++;
                }
                if (i < len && height[i])
                {
                    ans += tmp;
                }
            }
            if (end)
                break;
        }
        return ans;
    }
};
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        if (!len)
            return 0;
        int leftmax[len];
        int rightmax[len];
        leftmax[0] = height[0];
        rightmax[len - 1] = height[len - 1];
        int ans = 0;
        for (int i = 1; i < len; i++)
            leftmax[i] = max(leftmax[i - 1], height[i]);
        for (int i = len - 2; i >= 0; i--)
            rightmax[i] = max(rightmax[i + 1], height[i]);
        for (int i = 1; i < len; i++)
        {
            int tmp = min(leftmax[i], rightmax[i]) - height[i];
            if (tmp > 0)
                ans += tmp;
        }
        return ans;
    }
};
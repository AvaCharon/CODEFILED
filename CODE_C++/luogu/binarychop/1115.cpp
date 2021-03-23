#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    int pre = 0, maxAns = nums[0];
    for (const auto &x : nums)
    {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    cout<<maxAns;
    return 0;
}
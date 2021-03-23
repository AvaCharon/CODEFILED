class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int len=candyType.size();
        int half=len/2;
        unordered_set<int> us;
        int sum=0;
        for(int i=0;i<len;i++)
        {
            if(us.insert(candyType[i]).second)sum++;
            if(sum>=half)break;
        }
        return sum;
    }
};
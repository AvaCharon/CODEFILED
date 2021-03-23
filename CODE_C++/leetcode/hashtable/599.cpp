class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        map<string, int> mapp;
        map<int, vector<string>> anss;
        int len1 = list1.size();
        int len2 = list2.size();
        for (int i = 0; i < len1; i++)
        {
            mapp[list1[i]] = i;
        }
        for (int i = 0; i < len2; i++)
        {
            if (mapp.find(list2[i]) != mapp.end())
            {
                anss[i + mapp[list2[i]]].push_back(list2[i]);
            }
        }
        return anss.begin()->second;
    }
};
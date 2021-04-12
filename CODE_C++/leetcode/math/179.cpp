class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string ans;
        vector<string> itos;
        for (int it : nums)
            itos.push_back(to_string(it));
        int len = itos.size();
        sort(itos.begin(), itos.end(), [](string &a, string &b) { return a + b < b + a; });
        if (itos[len - 1] == "0")
            return "0";
        for (int j = len - 1; j >= 0; j--)
        {
            ans += itos[j];
        }
        return ans;
    }
};
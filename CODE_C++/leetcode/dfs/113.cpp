/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> anss;
    void dps(TreeNode *root, int summ)
    {
        if (root == nullptr)
            return;
        else
        {
            anss.push_back(root->val);
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val == summ)
            {
                ans.push_back(anss);
            }
            anss.pop_back();
            return;
        }
        else
        {
            dps(root->left, summ - root->val);
            dps(root->right, summ - root->val);
            anss.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return ans;
        dps(root, sum);
        return ans;
    }
};
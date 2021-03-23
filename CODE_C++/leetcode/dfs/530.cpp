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
    int ans = INT_MAX;
    set<int> tmp;

    void dfs(TreeNode *root)
    {
        tmp.insert(root->val);
        if (root->left)
        {
            dfs(root->left);
        }
        if (root->right)
        {
            dfs(root->right);
        }
        return;
    }

    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root);
        int pre = -1;
        for (auto &it : tmp)
        {
            if (pre != -1)
                ans = min(ans, it - pre);
            pre = it;
        }
        return ans;
    }
};
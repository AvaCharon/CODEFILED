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
    int ans;
    void dfs(TreeNode *root, int tmp)
    {
        if (root->left)
        {
            dfs(root->left, tmp * 10 + root->val);
        }
        if (root->right)
        {
            dfs(root->right, tmp * 10 + root->val);
        }
        if (!root->left && !root->right)
        {
            ans += tmp * 10 + root->val;
        }
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, 0);
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    int minDiffInBST(TreeNode *root)
    {
        if (!root)
            return 0;
        ans = root->val;
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
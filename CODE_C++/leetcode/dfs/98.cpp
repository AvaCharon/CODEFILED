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
    bool ans = true;
    int dfs(TreeNode *root, int a) //a=0  max,a=1  min
    {
        int leftt = -1, rightt = -1;
        if (root->left)
        {
            leftt = dfs(root->left, 0);
            if (leftt >= root->val)
                ans = false;
        }
        if (root->right)
        {
            rightt = dfs(root->right, 1);
            if (rightt <= root->val)
                ans = false;
        }
        if (!ans)
            return -1;
        int anss = root->val;
        if (a && leftt != -1)
            anss = min(anss, dfs(root->left, 1));
        if (!a && rightt != -1)
            anss = max(anss, dfs(root->right, 0));
        return anss;
    }
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return ans;
        if (root->left)
        {
            int leftt = dfs(root->left, 0);
            if (leftt >= root->val)
                ans = false;
        }
        if (root->right)
        {
            int rightt = dfs(root->right, 1);
            if (rightt <= root->val)
                ans = false;
        }
        return ans;
    }
};
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
    int ans;

    int dfs(TreeNode *root)
    {
        int leftt = 0, rightt = 0;
        if (root->left)
        {
            leftt = dfs(root->left);
        }
        if (root->right)
        {
            rightt = dfs(root->right);
        }
        ans += fabs(leftt - rightt);
        return leftt + rightt + root->val;
    }

    int findTilt(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        dfs(root);
        return ans;
    }
};
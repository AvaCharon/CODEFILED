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
    TreeNode *tmp;
    TreeNode *ans;
    bool head;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (!head)
        {
            ans = tmp = root;
            head = true;
        }
        else
        {
            tmp->left = nullptr;
            tmp->right = root;
            tmp = tmp->right;
        }
        dfs(root->right);
        return;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        ans = tmp = root;
        dfs(tmp);
        return ans;
    }
};
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
    int nminDepth(TreeNode *root, int n)
    {
        if (root == nullptr)
            return n;
        n++;
        if (root->left != nullptr && root->right == nullptr)
            return nminDepth(root->left, n);
        if (root->right != nullptr && root->left == nullptr)
            return nminDepth(root->right, n);
        if (root->right != nullptr && root->left != nullptr)
            return min(nminDepth(root->right, n), nminDepth(root->left, n));
        return n;
    }
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left != nullptr && root->right == nullptr)
            return nminDepth(root->left, 1);
        if (root->right != nullptr && root->left == nullptr)
            return nminDepth(root->right, 1);
        if (root->right != nullptr && root->left != nullptr)
            return min(nminDepth(root->right, 1), nminDepth(root->left, 1));
        return 1;
    }
};
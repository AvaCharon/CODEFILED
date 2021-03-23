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
    int nmaxDepth(TreeNode *root, int n)
    {
        if (root == nullptr)
            return n;
        n++;
        if (root->left != nullptr && root->right == nullptr)
            return nmaxDepth(root->left, n);
        if (root->right != nullptr && root->left == nullptr)
            return nmaxDepth(root->right, n);
        if (root->right != nullptr && root->left != nullptr)
            return max(nmaxDepth(root->right, n), nmaxDepth(root->left, n));
        return n;
    }
    bool isBalanced(TreeNode *root)
    {
        if(root==nullptr)return true;
        return (nmaxDepth(root->left,1)-nmaxDepth(root->right,1)<=1)&&(nmaxDepth(root->left,1)-nmaxDepth(root->right,1)>=-1);
    }
};

//
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};

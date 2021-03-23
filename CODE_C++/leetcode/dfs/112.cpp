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
    bool find;
    int summ(TreeNode *root, int summm)
    {
        if (find)
            return 0;
        if (root == nullptr)
            return summm;
        else if (root->left == nullptr && root->right == nullptr)
        {
            if (summm == root->val)
            {
                find = true;
                return 0;
            }
            return summm - root->val;
        }
        else
        {
            summ(root->left, summm - root->val);
            if (find)
                return 0;
            return summ(root->right, summm - root->val);
        }
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        summ(root, sum);
        return find;
    }
};
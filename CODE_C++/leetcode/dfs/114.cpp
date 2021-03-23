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
    void pretree(TreeNode *root, vector<TreeNode *> &l)
    {
        if (root != nullptr)
        {
            l.push_back(root);
            pretree(root->left, l);
            pretree(root->right, l);
        }
    }
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> l;
        pretree(root, l);
        int len = l.size();
        for (int i = 1; i < len; i++)
        {
            TreeNode *pt = l.at(i - 1);
            TreeNode *curr = l.at(i);
            pt->left = nullptr;
            pt->right = curr;
        }
        return;
    }
};
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
class Solution {
public:
    vector<int> ans;
    void getval(TreeNode* root)
    {
        if(root==nullptr)return ;
        if(root->left==nullptr)ans.push_back(root->val);
        else 
        {
            getval(root->left);
            ans.push_back(root->val);
        }
        getval(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)return ans;
        getval(root);
        return ans;
    }
};
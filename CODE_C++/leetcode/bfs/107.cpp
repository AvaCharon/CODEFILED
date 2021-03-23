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
    vector<int> anss;
    void bfs(TreeNode *root, int n)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            anss.push_back(root->val);
            return;
        }
        if (root->left != nullptr)
            bfs(root->left, n + 1);
        if (root->right != nullptr)
            bfs(root->right, n + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
    }
};


//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root==nullptr)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            int len=q.size();
            ans.push_back(vector<int>());
            for(int i=0;i<len;i++)
            {
                auto node = q.front();
                ans.back().push_back(node->val);
                q.pop();
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
            }
        }
        reserve(ans.begin(),ans.end());
        return ans;
    }
};
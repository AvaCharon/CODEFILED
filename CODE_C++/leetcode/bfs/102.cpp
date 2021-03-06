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
    vector<vector<int>> ans;
    vector<vector<int>> eachlevelOrder(TreeNode *root, int n)
    {
        if (root == nullptr)
            return ans;
        else
        {
            ans[n].push_back(root->val);
            if (root->left != nullptr)
                eachlevelOrder(root->left, n + 1);
            if (root->right != nullptr)
                eachlevelOrder(root->right, n + 1);
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return ans;
        else
        {
            ans[0].push_back(root->val);
            eachlevelOrder(root->left, 1);
            eachlevelOrder(root->right, 1);
        }
        return ans;
    }
};

//
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root)
        {
            return ret;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int currentLevelSize = q.size();
            ret.push_back(vector<int>());
            for (int i = 1; i <= currentLevelSize; ++i)
            {
                auto node = q.front();
                q.pop();
                ret.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ret;
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        stack<TreeNode *> q;
        stack<TreeNode *> p;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < len; i++)
            {
                TreeNode *pt = q.top();
                q.pop();
                ans.back().push_back(pt->val);
                if (pt->left)
                    p.push(pt->left);
                if (pt->right)
                    p.push(pt->right);
            }
            len = p.size();
            if (!len)
                break;
            ans.push_back(vector<int>());
            for (int i = 0; i < len; i++)
            {
                TreeNode *pt = p.top();
                p.pop();
                ans.back().push_back(pt->val);
                if (pt->right)
                    q.push(pt->right);
                if (pt->left)
                    q.push(pt->left);
            }
        }
        return ans;
    }
};
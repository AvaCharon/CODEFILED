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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            ans.push_back(q.front()->val);
            for (int i = 0; i < len; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->right)
                    q.push(tmp->right);
                if (tmp->left)
                    q.push(tmp->left);
            }
        }
        return ans;
    }
};
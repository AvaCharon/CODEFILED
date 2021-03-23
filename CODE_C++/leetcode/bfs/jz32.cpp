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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty())
        {
            int len = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < len; i++)
            {
                TreeNode *tmp = q.front();
                ans[cnt].push_back(tmp->val);
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            cnt++;
        }
        return ans;
    }
};
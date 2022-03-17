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
    int pretree(TreeNode *root, unordered_map<long long, int> &prefix, long long curr, int target) //前缀和
    {
        if (!root)
            return 0;
        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - target))
            ret = prefix[curr - target];
        prefix[curr]++;
        ret += pretree(root->left, prefix, curr, target);
        ret += pretree(root->right, prefix, curr, target);
        prefix[curr]--;

        return ret;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        return pretree(root, prefix, 0, targetSum);
    }
};
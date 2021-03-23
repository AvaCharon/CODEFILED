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
    vector<TreeNode*> allgeneratetrees(int start,int end)
    {
        if(start>end)
            return {nullptr};
        vector<TreeNode*> alltrees;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> lefttree = allgeneratetrees(start,i-1);
            vector<TreeNode*> righttree = allgeneratetrees(i+1,end);
        for(auto &k : lefttree)
        {
            for(auto &q : righttree)
            {
                TreeNode* root= new TreeNode(i);
                root->left=k;
                root->right=q;
                alltrees.emplace_back(root);
            }
        }
        }
        return alltrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n)return {};
        return allgeneratetrees(1,n);
    }
};
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
    vector<string> ans;
    string str;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        string temp = str;
        while (true)
        {
            int t = root->val;
            t = t % 10 + '0';
            temp += t;
            t /= 10;
            if (t == 0)
            {
                break;
            }
        }
        if (!root->left && !root->right)
        {
            ans.push_back(str);
            str = temp;
            return;
        }
        str += "->";
        if (root->left)
        {
            dfs(root->left);
        }
        if (root->right)
        {
            dfs(root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return ans;
        dfs(root);
        return ans;
    }
};


//

class Solution {
public:
    void construct_paths(TreeNode* root, string path, vector<string>& paths) {
        if (root != nullptr) {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {  // 当前节点是叶子节点
                paths.push_back(path);                              // 把路径加入到答案中
            } else {
                path += "->";  // 当前节点不是叶子节点，继续递归遍历
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }
};

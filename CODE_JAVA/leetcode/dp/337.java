/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {

    Map<TreeNode, Integer> a = new HashMap<TreeNode, Integer>();
    Map<TreeNode, Integer> b = new HashMap<TreeNode, Integer>();

    public int rob(TreeNode root) {
        dfs(root);
        return Math.max(a.getOrDefault(root, 0), b.getOrDefault(root, 0));
    }

    public void dfs(TreeNode root) {
        if (root == null)
            return;
        dfs(root.left);
        dfs(root.right);
        a.put(root, root.val + b.getOrDefault(root.left, 0) + b.getOrDefault(root.right, 0));
        b.put(root, Math.max(a.getOrDefault(root.left, 0), b.getOrDefault(root.left, 0))
                + Math.max(a.getOrDefault(root.right, 0), b.getOrDefault(root.right, 0)));
        return;
    }
}
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public int[] levelOrder(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if (root == null)
            return new int[0];
        Queue<TreeNode> qt = new LinkedList<TreeNode>();
        qt.add(root);
        while (!qt.isEmpty()) {
            TreeNode tmp = qt.poll();
            ans.add(tmp.val);
            if (tmp.left != null)
                qt.add(tmp.left);
            if (tmp.right != null)
                qt.add(tmp.right);
        }
        int[] res = new int[ans.size()];
        int i = 0;
        for (int it : ans)
            res[i++] = it;
        return res;
    }
}
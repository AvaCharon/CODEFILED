import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 * }
 */

public class Solution {
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型二维数组
     */

    private void firstview(TreeNode root, ArrayList<Integer> ans) {
        if (root == null)
            return;
        ans.add(root.val);
        if (root.left != null)
            firstview(root.left, ans);
        if (root.right != null)
            firstview(root.right, ans);
    }

    private void midview(TreeNode root, ArrayList<Integer> ans) {
        if (root == null)
            return;
        if (root.left != null)
            midview(root.left, ans);
        ans.add(root.val);
        if (root.right != null)
            midview(root.right, ans);
    }

    private void lastview(TreeNode root, ArrayList<Integer> ans) {
        if (root == null)
            return;
        if (root.left != null)
            lastview(root.left, ans);
        if (root.right != null)
            lastview(root.right, ans);
        ans.add(root.val);
    }

    private static final int[] toIntArray(ArrayList<Integer> arrayList) {
        int[] intArray = arrayList.stream().mapToInt(Integer::intValue).toArray();
        return intArray;
    }

    public int[][] threeOrders(TreeNode root) {
        int[][] ans = new int[3][];
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        ArrayList<Integer> c = new ArrayList<Integer>();

        firstview(root, a);
        midview(root, b);
        lastview(root, c);

        ans[0] = toIntArray(a);
        ans[1] = toIntArray(b);
        ans[2] = toIntArray(c);

        return ans;
    }

}
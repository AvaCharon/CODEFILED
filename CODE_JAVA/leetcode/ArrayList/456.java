import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public boolean find132pattern(int[] nums) {
        int len = nums.length;
        Deque<Integer> D = new LinkedList<Integer>();
        D.push(nums[len - 1]);
        int maxn = Integer.MIN_VALUE;

        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < maxn)
                return true;
            while (!D.isEmpty() && nums[i] > D.peek())
                maxn = D.pop();
            if (nums[i] > maxn)
                D.push(nums[i]);
        }
        return false;
    }
}

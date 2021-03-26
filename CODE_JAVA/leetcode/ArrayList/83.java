import java.util.HashSet;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        HashSet<Integer> hs = new HashSet<>();
        ListNode pre, ans;
        ans = pre = head;
        while (head != null) {
            if (!hs.add(head.val)) {
                pre.next = head.next;
            } else
                pre = head;
            head = head.next;
        }
        return ans;
    }
}
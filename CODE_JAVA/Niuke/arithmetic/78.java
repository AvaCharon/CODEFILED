//反转链表
/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if (head == null)
            return null;
        ListNode a = head.next;
        head.next = null;
        ListNode b = null;
        while (a != null) {
            b = a.next;
            a.next = head;
            head = a;
            a = b;
        }
        return head;
    }
}
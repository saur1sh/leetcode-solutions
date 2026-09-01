/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head, prev = null, next;
        Set<Integer> set = new HashSet<>();
        while (curr != null) {
            if (set.contains(curr.val)) {
                while(curr.next!=null && set.contains(curr.next.val)) {
                   curr = curr.next; 
                }
                if(curr.next==null) {
                    prev.next = null;
                    curr = null;
                }
                else {
                    next = curr.next;
                    prev.next = curr.next;
                    curr = next;
                }

            } else {
                set.add(curr.val);
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}
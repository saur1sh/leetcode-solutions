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
    public ListNode sortList(ListNode head) {
        if(head==null) {
            return null;
        }
        List<ListNode> ll = new ArrayList<>();
        while(head!=null) {
            ll.add(head);
            head = head.next;
        }
        ll.sort(Comparator.comparingInt(node -> node.val));
        ListNode newHead = ll.get(0);
        ListNode curr = newHead;
        for(int i=0; i<ll.size(); i++) {
            curr.next = ll.get(i);
            curr = curr.next;
        }
        curr.next = null;
        return newHead;
    }
}
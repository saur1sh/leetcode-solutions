/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=1, i=1;
        ListNode* curr = head;
        while(curr->next!=NULL){
        	curr = curr->next;
        	c++;
        }
        if(c==n){
            head=head->next;
            return head;
        }
        curr=head;
        while(i<c-n){
            curr = curr->next;
            i++;
        }
        ListNode* next = curr;
        next = next->next->next;
        curr->next = next;
        return head;
    }
};
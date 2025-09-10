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
        ListNode* curr = head;
        int size = 1;
        while(curr!=NULL && curr->next!=NULL) {
            curr = curr->next;
            size++;
        }
        if(size==1) {
            return NULL;
        }
        int hops = size-n;
        curr = head;
        int i=1;
        if(size==n) {
            curr = curr->next;
            head = curr;
            return head;
        }
        while(i!=hops) {
            curr = curr->next;
            i++;
        }
        if(n==1) {
            curr->next = NULL;
        }
        else {
            ListNode* next = curr->next->next;
            curr->next = next;
        }
        return head;
    }
};
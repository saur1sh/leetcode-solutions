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
        ListNode* t1 = head;
        ListNode* t2 = head;
        ListNode* prev = NULL;
        while(n--) {
            t2=t2->next;
        }
        while(t2) {
            prev = t1;
            t1=t1->next;
            t2=t2->next;
        }
        if(prev==NULL) {
            head=head->next;
        }
        else
            prev->next = t1->next;
        delete t1;
        return head;
    }
};
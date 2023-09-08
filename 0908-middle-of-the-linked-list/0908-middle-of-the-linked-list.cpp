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
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        ListNode* t1 = head;
        ListNode* t2 = head;
        while(t2 && t2->next) {
            t1 = t1->next;
            if(t2->next)
                t2 = t2->next->next;
        }
        return t1;
    }
};
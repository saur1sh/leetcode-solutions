/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pt1 = headA;
        unordered_map <ListNode*, bool> mp;
        while(pt1!=nullptr) {
            mp[pt1] = true;
            pt1 = pt1->next;
        }
        pt1 = headB;
        while(pt1!=nullptr) {
            if(mp.contains(pt1)) {
                return pt1;
            }
            else {
                pt1 = pt1->next;
            }
        }
        return NULL;
    }
};
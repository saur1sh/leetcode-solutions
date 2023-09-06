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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        int n=0;
        ListNode* curr = head;
        for (ListNode* node = head; node; node = node->next)
            n++;
        int parts = n/k, r=n%k;
        ListNode *prev = NULL;
        for(int i=0; curr && i<k; i++, r--) {
            ans[i]=curr;
            for(int j=0; j<parts+(r>0); j++) {
                if(curr==NULL)
                    break;
                prev = curr;
                curr = curr->next;
            }
            prev->next=NULL;
        }
        return ans;
    }
};
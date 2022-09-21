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
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(count%2!=0) count = (count+1)/2;
        else count=(count/2)+1;
        temp = head;
        int c=1;
        while(c!=count){
            temp=temp->next;
            c++;
        }
        return temp;
    }
};
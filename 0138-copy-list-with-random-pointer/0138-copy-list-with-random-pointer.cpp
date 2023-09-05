/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        unordered_map<Node*, Node*> mp;
        Node* curr = new Node(head->val);
        Node* ptr=head->next;
        Node* head2 = curr;
        mp[head] = curr;
        while(ptr!=NULL) {
            Node* nextNode = new Node(ptr->val);
            mp[ptr] = nextNode;
            ptr = ptr->next;
            curr->next = nextNode;
            curr = curr->next;
        }
        ptr=head;
        curr=head2;
        while(ptr!=NULL) {
            curr->random = mp[ptr->random];
            curr = curr->next;
            ptr = ptr->next;
        }
        return head2;
    }
};
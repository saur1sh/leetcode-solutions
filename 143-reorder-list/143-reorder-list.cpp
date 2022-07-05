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
    void reorderList(ListNode* head) {
		ListNode* front = head;
		ListNode* back = head;
		int n = 1;
		while (back->next != NULL) {
			back = back->next;
			n++;
		}
		if (n % 2 == 0)
			n = n / 2;
		else
			n = (n + 1) / 2;
		back = head;
		int i = 1;
		while (i != n) {
			back = back->next;
			i++;
		}
		ListNode* curr = back;
		ListNode* prev = NULL;
		ListNode* next = NULL;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		for (i = 0; i < n; i++) {
			curr = front->next;
			front->next = prev;
			front = curr;
			next = prev->next;
			prev->next = curr;
			prev = next;
		}
	}
};
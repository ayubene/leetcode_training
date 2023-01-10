/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	struct ListNode* preslow = head;
	int num = n;
	while (fast) {
		fast = fast->next;
		if (num==0) {
			slow = slow->next;
		}
		else {
			num--;
		}
	}
	fast = slow->next;
	if (fast == NULL) {
		slow->next = fast;
	}
	else {
		slow->next = fast->next;
	}
	
	free(fast);
	return head;
}
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

struct ListNode* middleNode(struct ListNode* head) {
	int len = 0;
	struct ListNode* tmp = head;
	while (tmp) {
		len++;
		tmp = tmp->next;
	}
	tmp = head;
	for (int i = len / 2; i > 0; i--) {
		tmp = tmp->next;
	}
	return tmp;
}
//快慢指针法
//tmp1慢，tmp2快
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* tmp1 = head;
	struct ListNode* tmp2 = head;
	while (tmp2 && tmp2->next) {
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if (tmp2) {
			tmp2 = tmp2->next;
		}
	}
	return tmp1;
}
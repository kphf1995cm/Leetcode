/*
 *  Author: Peng
 *  Time: 2020-3-3
 *  Problem: 86. Partition List
 */

# include<iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* small = NULL;
		ListNode* pre,*temp;
		if (head == NULL||head->next==NULL)
			return head;
		if (head->val < x) {
			small = head;
			pre = head;
			temp = head->next;
		}
		else {
			pre = head;
			temp = head->next;
			while (temp != NULL)
			{
				if (temp->val < x) {
					pre->next = temp->next;
					small = temp;
					temp = temp->next;
					small->next = head;
					head = small;
					break;
				}
				pre = pre->next;
				temp = temp->next;
			}
		}
		while (temp != NULL) {
			if (temp->val < x) {
				if (small->next == temp) {
					small = temp;
					pre = pre->next;
					temp = temp->next;
				}
				else {
					pre->next = temp->next;
					temp->next = small->next;
					small->next = temp;
					small = temp;
					temp = pre->next;
				}
			}
			else {
				pre = pre->next;
				temp = temp->next;
			}
		}
		return head;
	}
};

int main() {
	Solution s;
	ListNode * head;
	head = new ListNode(2);
	int value[2] = { 3,1 };
	ListNode * temp = head;
	for (int i = 0; i < 2; i++) {
		ListNode * t = new ListNode(value[i]);
		temp->next = t;
		temp = t;
	}
	ListNode * res = s.partition(head, 2);
	while (res != NULL) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}
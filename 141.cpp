/*
 *  Author: Peng
 *  Time: 2020-3-3
 *  Problem: 141. Linked List Cycle
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
	bool hasCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
		if (head == NULL) {
			return false;
		}
		while (fast != NULL) {
			if (fast->next == NULL)
				return false;
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}
		return false;
	}
};

int main() {
	return 0;
}

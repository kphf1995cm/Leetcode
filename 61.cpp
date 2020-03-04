/*
 *  Author: Peng
 *  Time: 2020-3-4
 *  Problem: 61. Rotate List
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
	ListNode* rotateRight(ListNode* head, int k) {
		int size = 0;
		ListNode* temp = head;
		while (temp != NULL) {
			size++;
			temp = temp->next;
		}
		if (size <= 1)
			return head;
		k = k % size;
		if (k != 0) {
			ListNode *first, *last;
			int count = 0;
			temp = head;
			while (++count<size-k) {
				temp = temp->next;
			}
			first = temp->next;
			temp->next = NULL;
			temp = first;
			count = 0;
			if (k - 1 != 0) {
				while (++count < k - 1) {
					temp = temp->next;
				}
				last = temp->next;
				last->next = head;
			}
			else
				first->next = head;
			head = first;
		}
		return head;
	}
};

int main() {

}
/*
 *  Author: Peng
 *  Time: 2020-3-3
 *  Problem: 1019. Next Greater Node In Linked List
 *  Disc : An implementation of monotonous stack
 */

# include<iostream>
# include<vector>
# include<stack>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> value;
		while (head != NULL) {
			value.push_back(head->val);
			head = head->next;
		}
		vector<int> res(value.size(), 0); 
		stack<int> monotoneDecreasingStack;// save index
		for (size_t i = 0; i < value.size();i++) {
			while (monotoneDecreasingStack.empty() == false && value[monotoneDecreasingStack.top()] < value[i]) {
				res[monotoneDecreasingStack.top()] = value[i];
				monotoneDecreasingStack.pop();
			}
			monotoneDecreasingStack.push(i);
		}
		return res;
	}
};

int main() {

}
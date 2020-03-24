/*
 *  Author: Peng
 *  Time: 2020-3-23
 *  1038. Binary Search Tree to Greater Sum Tree
 */
# include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* bstToGst(TreeNode* root) {
		if (root != NULL) {
			TreeNode* r = root;
			int addSum = 0;
			dfs(r, addSum);
		}
		return root;
	}
	void dfs(TreeNode* r, int& addSum) {
		if (r->right != NULL) {
			dfs(r->right, addSum);
		}
		r ->val += addSum;
		addSum = r->val;
		if (r->left != NULL) {
			dfs(r->left, addSum);
		}
	}
};

int main() {
	return 0;
}
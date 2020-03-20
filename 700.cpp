/*
 *  Author: Peng
 *  Time: 2020-3-19
 *  Problem: 700. Search in a Binary Search Tree
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
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL || root->val==val)
			return root;
		if (root->val < val)
			return searchBST(root->right, val);
		else
			return searchBST(root->left, val);
	}
};

int main() {
	return 0;
}
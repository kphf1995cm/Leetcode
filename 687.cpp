/*
 *  Author: Peng
 *  Time: 2020-3-23
 *  687. Longest Univalue Path
 */

# include<iostream>
# include<queue>
# include<unordered_set>
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
	int maxPath=0;
	int longestUnivaluePath(TreeNode* root) {
		if (root = NULL)
			return 0;
		int leftChild = dfs(root->left, root->val);
		int rightChild = dfs(root->right, root->val);
		if (leftChild + rightChild > maxPath)
			maxPath = leftChild + rightChild;
		return maxPath;
	}
	int dfs(TreeNode*r,int parentVal) {
		if (r == NULL)
			return 0;
		int leftChild = dfs(r->left, r->val);
		int rightChild = dfs(r->right, r->val);
		if (leftChild + rightChild > maxPath)
			maxPath = leftChild + rightChild;
		if (r->val == parentVal) {
			leftChild = leftChild > rightChild ? leftChild : rightChild;
			return leftChild + 1;
		}
		else
			return 0;
	}
};

int main() {
	Solution s;
}
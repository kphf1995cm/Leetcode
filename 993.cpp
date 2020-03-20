/*
 *  Author: Peng
 *  Time: 2020-3-20
 *  993. Cousins in Binary Tree
 */

# include<iostream>
# include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct NodePLevel
{
	TreeNode* cur;
	int level;
	TreeNode* parent;
	NodePLevel(TreeNode* c, int l, TreeNode* p) {
		cur = c;
		level = l;
		parent = p;
	}
};

class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (root != NULL) {
			queue<NodePLevel> q;
			q.push(NodePLevel(root, 1, NULL));
			int hx=0, hy=0;
			TreeNode *px = NULL, *py = NULL;
			while (q.empty() == NULL) {
				NodePLevel temp = q.front();
				q.pop();
				if (temp.cur->val == x || temp.cur->val == y) {
					if (temp.cur->val == x) {
						hx = temp.level;
						px = temp.parent;
					}
					else {
						hy = temp.level;
						py = temp.parent;
					}
				}
				else {
					if (temp.cur->left != NULL) {
						q.push(NodePLevel(temp.cur->left, temp.level + 1, temp.cur));
					}
					if (temp.cur->right != NULL) {
						q.push(NodePLevel(temp.cur->right, temp.level + 1, temp.cur));
					}
				}
			}
			if (hx == hy&&px != py)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main() {

}
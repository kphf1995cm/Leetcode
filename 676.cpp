/*
 *  Author: Peng
 *  Time: 2020-3-20
 *  676. Implement Magic Dictionary
 */

# include<iostream>
# include<vector>
# include<unordered_set>
# include<string>
using namespace std;

class MagicDictionary {
public:
	/** Initialize your data structure here. */
	struct TreeNode {
		unordered_set<string> suffix;
		bool isWord;
		vector<TreeNode*> children;
		TreeNode() {
			isWord = false;
			children = vector<TreeNode*>(26, NULL);
		}
	};

	TreeNode *root;

	MagicDictionary() {
		root = new TreeNode();
	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (int i = 0; i < dict.size(); i++) {
			TreeNode *r = root;
			for (int j = 0; j < dict[i].size(); j++) {
				int branch = dict[i][j] - 'a';
				if (r->children[branch] == NULL) {
					TreeNode *temp = new TreeNode();
					r->children[branch] = temp;	
				}
				if (j != dict[i].size() - 1) {
					r->children[branch]->suffix.insert(dict[i].substr(j + 1, dict[i].size() - j - 1));
				}
				else
					r->children[branch]->isWord = true;
				r = r->children[branch];
			}
		}
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		TreeNode*r = root;
		for (int i = 0; i < word.size(); i++) {
			int branch = word[i] - 'a';
			if (i != word.size() - 1) {
				string tempSuffix = word.substr(i + 1, word.size() - i - 1);
				for (int j = 0; j < 26; j++) {
					if (j != branch&&r->children[j]!=NULL&&r->children[j]->suffix.count(tempSuffix) >= 1)
						return true;
				}
				if (r->children[branch] != NULL) {
					r = r->children[branch];
				}
				else
					return false;
			}
			else {
				for (int j = 0; j < 26; j++) {
					if (j != branch&&r->children[j] != NULL&&r->children[j]->isWord == true)
						return true;
				}
				return false;
			}
		}
		return false;
	}
};

int main() {
	MagicDictionary md;
	return 0;
}

/*
 *  Author: Peng
 *  Time: 2020-3-18
 *  Problem: 784. Letter Case Permutation
 */

# include<iostream>
# include<vector>
# include<unordered_set>
# include<string>
using namespace std;

class Solution {
public:

	unordered_set<char> alphabetList;
	int diff;

	vector<string> letterCasePermutation(string S) {
		diff = 'A' - 'a';
		for (auto i = 0; i < 26; i++) {
			alphabetList.insert(char('a' + i));
			alphabetList.insert(char('A' + i));
		}
		vector<string> res;
		if (S.size() != 0)
			res.push_back(S);
		traverse(S, res, 0);
		return res;
	}

	void traverse(string S,vector<string> &res, int index) {
		while (index<S.size()&&alphabetList.count(S[index]) == 0)
			index++;
		if (index < S.size()) {
			traverse(S, res, index + 1);
			if (S[index] >= 'a'&&S[index] <= 'z')
				S[index] = S[index] + diff;
			else
				S[index] = S[index] - diff;
			res.push_back(S);
			traverse(S, res, index + 1);
		}
	}
};

int main() {

	Solution s;
	vector<string> vecs=s.letterCasePermutation("a1b1");
	for (auto i = 0; i < vecs.size(); i++) {
		cout << vecs[i] << endl;
	}
}


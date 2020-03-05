/*
 *  Author: Peng
 *  Time: 2020-3-5
 *  Problem: 1249. Minimum Remove to Make Valid Parentheses
 */

# include<iostream>
# include<stack>
# include<unordered_set>
# include<string>
# include<map>
using namespace std;

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<pair<char, size_t>> parentheseIndex;
		for (size_t i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case '(':
				parentheseIndex.push(make_pair('(', i));
				break;
			case ')':
				if (parentheseIndex.empty() != true && parentheseIndex.top().first == '(')
					parentheseIndex.pop();
				else
					parentheseIndex.push(make_pair(')', i));
				break;
			default:
				break;
			}
		}
		unordered_set<size_t> removeIndex;
		while (parentheseIndex.empty() == false) {
			removeIndex.insert(parentheseIndex.top().second);
			parentheseIndex.pop();
		}
		string res;
		for (size_t i = 0; i < s.size(); i++) {
			if (removeIndex.count(i) == 0)
				res.insert(res.end(), s[i]);
		}
		return res;
	}
};

int main() {
	Solution s;
	cout << s.minRemoveToMakeValid("a)b(c)d") << endl;
	return 0;
}
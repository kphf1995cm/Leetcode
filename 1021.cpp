/*
 *  Author: Peng
 *  Time: 2020-3-16
 *  Problem: 1021. Remove Outermost Parentheses
 */

# include<iostream>
# include<string>
# include<vector>
using namespace std;

class Solution {
public:
	string removeOuterParentheses(string S) {
		int leftBracketNum = 0;
		string res;
		string temp;
		for (auto i = 0; i < S.size(); i++) {
			if (S[i] == '(') {
				leftBracketNum++;
				temp.insert(temp.end(), S[i]);
			}
			else {
				if (leftBracketNum - 1 != 0) {
					leftBracketNum--;
					temp.insert(temp.end(), S[i]);
				}
				else {
					res += temp.substr(1, temp.size() - 1);
					leftBracketNum = 0;
					temp = "";
				}
			}
		}
		return res;
	}
};

int main() {
	return 0;
}

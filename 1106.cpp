/*
 *  Author: Peng
 *  Time: 2020-3-7
 *  1106. Parsing A Boolean Expression
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Stack Implementation

class Solution {
public:
	bool parseBoolExpr(string expression) {
		stack<char> res;
		for (size_t i = 0; i < expression.size(); i++){
			switch (expression[i])
			{
			case '!':res.push(expression[i]); break;
			case '&':res.push(expression[i]); break;
			case '|':res.push(expression[i]); break;
			case '(':res.push(expression[i]); break;
			case ',':break;
			case ')': {
				vector<char> opeNum;
				while (res.top() != '(') {
					opeNum.push_back(res.top());
					res.pop();
				}
				res.pop();
				char opeSymbol = res.top();
				res.pop();
				if (opeSymbol == '!') {
					if (opeNum[0] == 't')
						res.push('f');
					else
						res.push('t');
				}
				else {
					if (opeSymbol == '&') {
						size_t j;
						for (j = 0; j < opeNum.size(); j++) {
							if (opeNum[j] == 'f')
								break;
						}
						if (j != opeNum.size())
							res.push('f');
						else
							res.push('t');
					}
					else {
						size_t j;
						for (j = 0; j < opeNum.size(); j++) {
							if (opeNum[j] == 't')
								break;
						}
						if (j != opeNum.size())
							res.push('t');
						else
							res.push('f');
					}
				}
				break;
			}
			default:
				res.push(expression[i]); break;
			}
		}
		if (res.top() == 't')
			return true;
		else
			return false;
	}
};

int main() {

}





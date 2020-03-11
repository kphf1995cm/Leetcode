/*
 *  Author: Peng
 *  Time: 2020-3-11
 *  392. Is Subsequence
 */


# include<iostream>
# include<string>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.size() > t.size())
			return false;
		int i=0, j;
		for (j = 0; j < t.size()&&i<s.size(); j++) {
			if (s[i] == t[j])
				i++;
		}
		return i == s.size();
	}
};

int main() {
	
}

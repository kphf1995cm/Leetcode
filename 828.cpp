/*
 *  Author: Peng
 *  Time: 2020-3-5
 *  Problem: 828.Count Unique Characters of All Substrings of a Given String
 */

# include<iostream>
# include<unordered_map>
//# include<math.h>
# include<string>
using namespace std;

class Solution {
public:
	const int mol = 1000000007;
	int uniqueLetterString(string s) {

		unordered_map<char, vector<int>> charIndexVec;
		unordered_map<char, int> charCurPoint;
		
		for (size_t i = 0; i < s.size(); i++) {
			if (charIndexVec.count(s[i]) == 0) {
				vector<int> temp;
				temp.push_back(i);
				charIndexVec[s[i]] = temp;
			}
			else
				charIndexVec[s[i]].push_back(i);
		}
		// Init charCurIndex, can omit
		for (int i = 0; i < 26; i++) {
			charCurPoint['A' + i] = 0;
		}

		int sum = 0;
		int begin, end;

		for (size_t i = 0; i < s.size(); i++) {
			int point = charCurPoint[s[i]];
			begin = (point == 0) ? 0 : charIndexVec[s[i]][point - 1] + 1;
			end = (point == charIndexVec[s[i]].size() - 1) ? s.size() - 1 : charIndexVec[s[i]][point + 1] - 1;
			sum = (sum + (i - begin + 1)*(end - i + 1)) % mol;
			charCurPoint[s[i]]++;
		}
		return sum;
	}
};

int main() {
	Solution s;
	cout<<s.uniqueLetterString("LEETCODE")<<endl;
	return 0;
}


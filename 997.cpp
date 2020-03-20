/*
 *  Author: Peng
 *  Time: 2020-3-20
 *  997. Find the Town Judge
 */

# include<iostream>
# include<unordered_set>
# include<unordered_map>
# include<vector>
using namespace std;

class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		unordered_set<int> normalMan;
		unordered_map<int, unordered_set<int>> judgeCandidate;
		for (int i = 0; i < trust.size(); i++) {
			normalMan.insert(trust[i][0]);
			if (normalMan.count(trust[i][1]) == 0) {
				if (judgeCandidate.count(trust[i][1]) == 0) {
					unordered_set<int> temp;
					temp.insert(trust[i][0]);
					judgeCandidate[trust[i][1]] = temp;
				}
				else
					judgeCandidate[trust[i][1]].insert(trust[i][0]);
			}
		}
		for (int i = 1; i <= N; i++) {
			if (normalMan.count(i) == 0 && judgeCandidate[i].size() == N - 1)
				return i;
		}
		return -1;
	}
};

int main() {
	Solution s;
	return 0;
}
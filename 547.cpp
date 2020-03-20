/*
 *  Author: Peng
 *  Time: 2020-3-20
 *  547. Friend Circles
 */

# include<iostream>
# include<vector>
# include<unordered_set>
using namespace std;

class Solution {
public:
	vector<int> pre;
	int findCircleNum(vector<vector<int>>& M) {
		pre.resize(M.size());
		for (int i = 0; i < M.size(); i++)
			pre[i] = i;
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M.size(); j++) {
				if (i != j) {
					if (M[i][j] == 1)
						join(i, j);
				}
			}
		}
		unordered_set<int> unions;
		for (int i = 0; i < M.size(); i++)
			unions.insert(find(i));
		return unions.size();

	}
	int find(int x) {
		int r = x;
		while (pre[r] != r)
			r = pre[r];
		int i = x,j;
		while (pre[i] != r) {
			j = pre[i];
			pre[i] = r;
			i = j;
		}
		return r;
	}

	void join(int x, int y) {
		int rx = find(x);
		int ry = find(y);
		if (rx != ry)
			pre[ry] = rx;
	}

};

int main() {

	Solution s;
}


/*
 *  Author: Peng
 *  Time: 2020-3-24
 *  329. Longest Increasing Path in a Matrix
 */

# include<iostream>
# include<vector>
# include<unordered_set>
using namespace std;

class Solution {
public:
	vector<int> X = { 1, -1, 0, 0 };
	vector<int> Y = { 0, 0, 1, -1 };

	int dfs(int i, int j, vector<vector<int> >& dp, vector<vector<int> >& matrix) {
		if (dp[i][j] != -1)
			return dp[i][j];
		dp[i][j] = 1;
		for (int k = 0; k<4; k++) {
			int x = i + X[k], y = j + Y[k];
			if (x >= 0 && x<matrix.size() && y >= 0 && y<matrix[0].size() && matrix[x][y]>matrix[i][j])
				dp[i][j] = max(dp[i][j], 1 + dfs(x, y, dp, matrix));
		}
		return dp[i][j];
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), -1));
		int ans = 1;
		for (int i = 0; i<matrix.size(); i++)
			for (int j = 0; j<matrix[0].size(); j++)
				ans = max(ans, dfs(i, j, dp, matrix));
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> m(3,vector<int>(3));
	int nums[][3] = { {9,9,4},{6,6,8},{2,1,1} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			m[i][j] = nums[i][j];
	}
	cout<<s.longestIncreasingPath(m)<<endl;
	return 0;
}

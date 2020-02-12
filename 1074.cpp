/*
 *  Author: Peng
 *  Time: 2020-2-11
 *  Problem: Number of Submatrices That Sum to Target
 */

# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;

class Solution {
public:
	// Time Limit Exceeded: 38/38 test cases passed, but took too long
	// Time complexity: O(n^4)
	int numSubmatrixSumTarget2(vector<vector<int>>& matrix, int target) {
		int x = matrix.size();
		int y;
		if (x > 0) {
			y = matrix[0].size();
			if (y > 0) {
				int res = 0;
				vector<vector<int>> prefixSum(x+1,vector<int>(y+1));
				// init 0 row 0 col
				for (int i = 0; i <= x; i++)
					prefixSum[i][0] = 0;
				for (int i = 0; i <= y; i++)
					prefixSum[0][i] = 0;
				for (int j = 1; j <= y; j++) {
					for (int i = 1; i <= x; i++) {
						prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
						if (prefixSum[i][j] == target)
							res++;
						for (int m = 0; m < i; m++) {
							for (int n = 0; n < j; n++) {
								if (m == 0 && n == 0) continue;
								if (prefixSum[i][j] - prefixSum[i][n] - prefixSum[m][j] + prefixSum[m][n] == target)
									res++;
							}
						}
					}
				}
				return res;
			}
			else
				return 0;
		}
		else 
			return 0;
	}

	// running rows solution
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int count = 0;
		for (int L = 0; L < cols; L++) {
			vector<int> runningRows(rows, 0);
			for (int R = L; R < cols; R++) {
				for (int i = 0; i < rows; i++) {
					runningRows[i] += matrix[i][R];
				}
				int sum = 0;
				unordered_map<int, int> prefixCols;
				for (int i = 0; i < rows; i++) {
					prefixCols[sum]++;
					sum += runningRows[i];
					if (prefixCols.count(sum - target)>0) {
						count += prefixCols[sum - target];
					}
				}
			}
		}
		return count;
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix;
	int target = 0;
	int tmp[5][6] = { { 0, 1, 1, 1, 0, 1 },{ 0, 0, 0, 0, 0, 1 },{ 0, 0, 1, 0, 0, 1 },{ 1, 1, 0, 1, 1, 0 },{ 1, 0, 0, 1, 0, 0 } };
	for (int i = 0; i < 5; i++) {
		vector<int> vec;
		for (int j = 0; j < 6; j++) {	
			vec.push_back(tmp[i][j]);
		}
		matrix.push_back(vec);
	}
	int res = s.numSubmatrixSumTarget(matrix,target);
	cout << res;
	return 0;
}

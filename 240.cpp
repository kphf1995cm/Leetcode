/*
 *  Author: Peng
 *  Time: 2020-3-9
 *  240. Search a 2D Matrix II
 */

# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() > 0 && matrix[0].size() > 0)
			return divideAndConquer(matrix, target, 0, 0, matrix[0].size() - 1, matrix.size() - 1);
		else
			return false;
	}
	bool divideAndConquer(vector<vector<int>>& matrix, int target, int left,int top,int right,int down) {
		if (left > right || top > down)
			return false;
		if (left == right&&top == down) {
			return matrix[top][left] == target;
		}
		else {
			int middleRow = (top + down) / 2;
			int middleCol = (left + right) / 2;
			if (matrix[middleRow][middleCol] == target)
				return true;
			else {
				if (matrix[middleRow][middleCol] > target) {
					bool temp = divideAndConquer(matrix,target,left,top,middleCol-1,middleRow-1);
					temp = temp || divideAndConquer(matrix,target,left,middleRow,middleCol-1,down);
					temp = temp || divideAndConquer(matrix,target,middleCol,top,right,middleRow-1);
					return temp;
				}
				else {
					bool temp = divideAndConquer(matrix, target, middleCol + 1, middleRow + 1, right, down);
					temp = temp || divideAndConquer(matrix, target, left, middleRow + 1, middleCol, down);
					temp = temp || divideAndConquer(matrix, target, middleCol + 1, top, right, middleRow);
					return temp;
				}
			}
		}
	}
};

int main() {
	return 0;
}

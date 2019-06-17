/**
  * Time:2019-6-17
  * Author:echorez
  * Email: kp18@mails.tsinghua.edu.cn
  */

# include<iostream>
# include<vector>
# include<unordered_map>
# include<string>
using namespace std;

class Solution {
private:
	int xNum;
	int yNum;
public:
	unordered_map<string, int> memoPath;
	int max(int x, int y) {
		return x > y ? x : y;
	}
	int cherryPickup(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		xNum = grid[0].size();
		yNum = grid.size();
		return max(0,dp(0, 0, 0,grid));
	}
	int dp(int xA, int yA, int xB, vector<vector<int>>& grid) { //represent cur position to destination can pickup cherry num
		int yB = xA + yA - xB;
		string memoKey = to_string(xA) + '-' + to_string(yA) + '-' + to_string(xB);
		if (memoPath.count(memoKey) != 0)
			return memoPath[memoKey];
		if (xA == xNum || yA == yNum || xB == xNum || yB == yNum)
			return INT_MIN;
		if (grid[xA][yA] == -1 || grid[xB][yB] == -1)
			return INT_MIN;;
		int curPosCollectCherry;
		if (xA != xB)
			curPosCollectCherry = grid[xA][yA] + grid[xB][yB];
		else
			curPosCollectCherry = grid[xA][yA];
		if (xA == xNum - 1 && yA == yNum - 1)
			return curPosCollectCherry;
		int curPathCollectCherry = max(dp(xA + 1, yA, xB + 1, grid), dp(xA, yA + 1, xB + 1, grid));
		int temp = max(dp(xA + 1, yA, xB, grid), dp(xA, yA + 1, xB, grid));
		curPathCollectCherry = max(curPathCollectCherry, temp);
		int maxCollectCherry = curPosCollectCherry + curPathCollectCherry;
		memoPath[memoKey] = maxCollectCherry;
		return maxCollectCherry;
	}
};

int main() {
	cout << INT_MIN;
}
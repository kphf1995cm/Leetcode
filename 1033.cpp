/*
 *  Author: Peng
 *  Time: 2020-3-24
 *  1033. Moving Stones Until Consecutive
 */

# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> temp;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		sort(temp.begin(),temp.end());
		vector<int> res;
		res.push_back(minMoves(temp[0], temp[1], temp[2]));
		res.push_back(maxMoves(temp[0], temp[1], temp[2]));
		return res;
	}
	int minMoves(int a,int b,int c) {
		if (a + 1 == b&&b + 1 == c)
			return 0;
		if (a + 2 >= b || b + 2 >= c)
			return 1;
		int min = INT_MAX, temp;
		//pick a
		for (int i = b + 1; i < c; i++) {
			temp = minMoves(b,i,c);
			if (min > temp)
				min = temp;
		}
		//pick c
		for (int i = a + 1; i < b; i++) {
			temp = minMoves(a,i,b);
			if (min > temp)
				min = temp;
		}
		return min + 1;
	}
	int maxMoves(int a,int b,int c) {
		if (a + 1 == b&&b + 1 == c)
			return 0;
		return c - a - 2;
	}
};

int main() {
	Solution s;
	vector<int> res=s.numMovesStones(2, 5, 1);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}

/*
 *  Author: Peng
 *  Time: 2020-3-4
 *  Problem: 149. Max Points on a Line
 */

# include<iostream>
# include<unordered_map>
# include<math.h>
# include<vector>
using namespace std;

class Solution{
public:
	//T(n) = O(n^2)
	//S(n) = O(n)
	int maxPoints(vector<vector<int>>& points) {

		if (points.empty()) { return 0; }
		if (points.size() == 1) { return 1; }

		int Max = 0;
		for (int i = 0; i < points.size(); i++) {
			int same = 1;
			unordered_map<double,int> mym;
			int localmax = 0;
			for (int j = i + 1; j < points.size(); j++) {
				if (samepoint(points[i],points[j])) {
					same++;
				}
				else {
					double myslope = slope(points[i],points[j]);
					mym[myslope]++;
					localmax = max(localmax, mym[myslope]);
				}

			}
			Max = max(Max, localmax + same);
		}
		return Max;
	}
	double slope(vector<int>& a, vector<int>& b) {
		if (a[0] == b[0]) { return INT_MAX; }
		if (a[1] == b[1]) { return 0; }
		return (1.0*a[0] - 1.0*b[0]) / (1.0*a[1] - 1.0*b[1]);
	}
	bool samepoint(vector<int>& a, vector<int>& b) {
		return a[0] == b[0] && a[1] == b[1];
	}
};

int main() {
	return 0;
}

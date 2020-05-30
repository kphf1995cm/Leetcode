/*
 *  Author: Peng
 *  Time: 2020-3-24
 *  220. Contains Duplicate III
 */

# include<iostream>
# include<vector>
# include<set>
# include<map>
# include<queue>
# include<deque>
using namespace std;

class Solution2 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long> kVals;
		int i;
		for (i = 0; i < nums.size(); i++) {
			long cur = nums[i];
			auto it = kVals.lower_bound(cur - t);
			if (it != kVals.end()) {
				if (abs(*it - cur) <= t)
					return true;
			}	
			kVals.insert(cur);
			if (kVals.size() > k) {
				kVals.erase(nums[i - k]);
			}
		}
		return false;
	}
};

class Solution3 {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		if (coordinates.size() <= 2)
			return true;
		multimap<int, int> cds;
		bool vertical = false;
		int verticalX;
		for (int i = 0; i<coordinates.size(); i++) {
			cds.insert(make_pair(coordinates[i][0], coordinates[i][1]));
			if (cds.count(coordinates[i][0]) >= 2) {
				vertical = true;
				verticalX = i;
			}
		}
		if (vertical) {
			return cds.count(verticalX) == coordinates.size();
		}
		auto secondIter = cds.begin();
		secondIter++;
		double slope = ((secondIter)->second - cds.begin()->second) / ((secondIter)->first - cds.begin()->first);
		auto preIter = secondIter;
		auto iter =cds.begin();
		iter++;
		iter++;
		for (; iter != cds.end(); iter++,preIter++) {
			if ((iter->second - (preIter)->second) / (iter->first - (preIter)->first) != slope)
				return false;
		}
		//double slope=(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);

		/*for(int i=2;i<coordinates.size();i++){
		if((coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0])!=slope)
		return false;
		}*/

		return true;
	}
};

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<pair<int,int>> qValIdx;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			if (qValIdx.empty() == false && i - qValIdx.front().second >= k)
				qValIdx.pop_front();
			while (qValIdx.empty() == false && qValIdx.back().first <= nums[i])
				qValIdx.pop_back();
			qValIdx.push_back(make_pair(nums[i],i));
			if(i>=k-1)
				res.push_back(qValIdx.front().first);
		}
		return res;
	}
};

int main() {
	Solution s;
	int nums[] = {1,3,-1,-3,5,3,6,7};
	vector<int> val;
	for (int i = 0; i < 8; i++)
		val.push_back(nums[i]);
	vector<int> res = s.maxSlidingWindow(val,3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}
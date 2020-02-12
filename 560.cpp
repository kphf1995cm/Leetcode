/*
*  Author: Peng
*  Time: 2020-2-11
*  Problem: Subarray Sum Equals K
*/

# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> prefixMap;
		int res = 0;
		prefixMap[0]=1;
		int prefixSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			prefixSum += nums[i];
			if (prefixMap.count(prefixSum - k) != 0)
				res += prefixMap[prefixSum - k];
			prefixMap[prefixSum]++;
		}
		return res;
	}
};

int main() {
	cout << INT_MAX;
}
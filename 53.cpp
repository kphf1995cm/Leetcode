/*
 *  Author: Peng
 *  Time: 2020-3-8
 *  53. Maximum Subarray
 */

# include<iostream>
# include<set>
# include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() <= 0)
			return 0;
		long long maxSum = INT_MIN;
		set<long long> sums;
		sums.insert(0);
		long long sum = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			sum += nums[i];
			long long temp = sum - (*sums.begin());
			if (temp > maxSum)
				maxSum = temp;
			sums.insert(sum);
		}
		return maxSum;
	}
};

int main() {
	return 0;
}
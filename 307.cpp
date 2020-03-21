/*
 *  Author: Peng
 *  Time: 2020-3-21
 *  307. Range Sum Query - Mutable
 */

# include<iostream>
# include<vector>
using namespace std;

class NumArray {
public:
	vector<int> prefixSum;
	vector<int> originValue;
	NumArray(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			originValue.push_back(nums[i]);
			sum += nums[i];
			prefixSum.push_back(sum);
		}
	}

	void update(int i, int val) {
		int diff = val - originValue[i];
		originValue[i] = val;
		for (int j = i; j < prefixSum.size(); j++)
			prefixSum[j] += diff;
	}

	int sumRange(int i, int j) {
		if (i > 0) {
			return prefixSum[j] - prefixSum[i-1];
		}
		else {
			return prefixSum[j];
		}
	}
};

int main() {
	return 0;
}
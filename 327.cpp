/*
 *  Author: Peng
 *  Time: 2020-3-8
 *  327. Count of Range Sum
 */


#include<iostream>
#include<set>
#include<vector>

using namespace std;
class Solution {
public:
	int countRangeSum2(vector<int>& nums, int lower, int upper) {
		int res = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			long previous = 0;
			for (size_t j = i; j < nums.size(); j++) {
				previous += nums[j];
				if (previous >= lower&&previous <= upper)
					res++;
			}
		}
		return res;
	}

	int countRangeSum(vector<int>& nums, int lower, int upper) {
		multiset<long long> sums;
		long long sum = 0;
		int res = 0;
		sums.insert(0);
		for (size_t i = 0; i < nums.size(); i++) {
			sum += nums[i];
			res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
			sums.insert(sum);
		}
		return res;
	}
};

int main() {

}
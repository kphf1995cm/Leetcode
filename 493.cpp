/*
 *  Author: Peng
 *  Time: 2020-3-9
 *  493. Reverse Pairs
 */

# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		return mergesort(nums, 0, nums.size() - 1);
	}
	int mergesort(vector<int>&nums,int low,int high) {
		if (low >= high)
			return 0;
		int middle = (low + high) / 2;
		int res = mergesort(nums, low, middle) + mergesort(nums, middle + 1, high);
		int i, j=middle+1;
		for (i = low; i <= middle; i++) {
			while (j <= high&&nums[i] > 2 * nums[j])
				j++;
			res += j - middle-1;
		}
		merge(nums, low, middle, high);
		return res;
	}
	void merge(vector<int>&nums, int low, int middle, int high) {
		int n1 = middle - low + 1;
		int n2 = high - middle;
		vector<int> left;
		vector<int> right;
		for (int i = low; i <= middle; i++)
			left.push_back(nums[i]);
		for (int i = middle + 1; i <= high; i++) {
			right.push_back(nums[i]);
		}
		int i = 0, j = 0;
		for (int k = low; k <= high; k++) {
			if (j >= n2 || (i < n1&&left[i] <= right[j]))
				nums[k] = left[i++];
			else
				nums[k] = right[j++];
		}
	}
};

int main() {
	return 0;
}


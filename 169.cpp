/*
 *  Author: Peng
 *  Time: 2020-3-8
 *  169. Majority Element
 */
# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int pre = nums[0];
		int count = 1;
		for (size_t i = 1; i < nums.size(); i++) {
			if (count == 0) {
				count = 1;
				pre = nums[i];
			}
			else {
				if (pre == nums[i])
					count++;
				else
					count--;
			}
		}
		return pre;
	}
};

int main() {

}


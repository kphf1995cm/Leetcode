/*
*  Author: Peng
*  Time: 2020-2-11
*  Problem: Missing Number
*/

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		vector<int> temp(n + 1);
		for (int i = 0; i<n; i++) {
			temp[nums[i]] = 1;
		}
		for (int i = 0; i<n + 1; i++) {
			if (temp[i] != 1) {
				return i;
			}
		}
		return 0;
	}

	// Utilize xor operator
	// eg: x^0 = x; x^x = 0

	int missingNumber2(vector<int>& nums) {
		int missing = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			missing ^= i^nums[i];
		}
		return missing;
	}
};

int main() {
	Solution s;
	vector<int> nums;
	//int temp[] = { 3,0,1 };
	int temp[] = { 9,6,4,2,3,5,7,0,1 };
	for (int i = 0; i < 9; i++)
		nums.push_back(temp[i]);
	cout << s.missingNumber2(nums) << endl;
	return 0;
}
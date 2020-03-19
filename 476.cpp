/*
 *  Author: Peng
 *  Time: 2020-3-19
 *  Problem: 476. Number Complement
 */

# include<iostream>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int temp = num;
		int bitnum = 0;
		if (temp == 0)
			bitnum = 1;
		while (temp) {
			bitnum++;
			temp = temp >> 1;
		}
		return num ^ (INT_MAX >> (31-bitnum));
	}
};

int main() {
	Solution s;
	cout<<s.findComplement(0);
}
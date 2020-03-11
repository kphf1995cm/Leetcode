/*
 *  Author: Peng
 *  Time: 2020-3-11
 *  121. Best Time to Buy and Sell Stock
 */

# include<iostream>
# include<vector>
using namespace std;

// i<=j, max(price[j]-price[i]) 
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int res = 0;
		int preMin = prices[0];
		for (size_t i = 1; i < prices.size(); i++) {
			int temp = prices[i] - preMin;
			if (res < temp)
				res = temp;
			if (preMin > prices[i])
				preMin = prices[i];
		}
		return res;
	}
};

int main() {

}
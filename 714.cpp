/*
 *  Author: Peng
 *  Time: 2020-3-11
 *  714. Best Time to Buy and Sell Stock with Transaction Fee
 */

# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		if (prices.size() < 2)
			return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(2));
		// 0 buy, 1 sell
		dp[0][0] = -prices[0] - fee;
		dp[0][1] = 0;

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = mymax(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
			dp[i][1] = mymax(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}

		return dp[prices.size() - 1][1];
	}
	int mymax(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {
	return 0;
}
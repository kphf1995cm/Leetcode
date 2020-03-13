/*
 *  Author: Peng
 *  Time: 2020-3-11
 *  188. Best Time to Buy and Sell Stock IV
 */
# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		if (k >= prices.size())
			return greedyBuyStock(prices);
		vector<int> local(k + 1, 0);
		vector<int> global(k + 1, 0);
		for (int i = 0; i < prices.size()-1; i++) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 1; j--) {
				local[j] = mymax(global[j - 1] + mymax(diff, 0), local[j] + diff);
				global[j] = mymax(local[j], global[j]);
			}
		}
		return global[k];
	}

	int greedyBuyStock(vector<int>& prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1])
				res += prices[i] - prices[i - 1];
		}
		return res;
	}

	int mymax(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {
	return 0;
}


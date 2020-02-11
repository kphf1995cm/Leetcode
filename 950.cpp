/*
 *  Author: Peng
 *  Time: 2020-2-11
 *  Problem: Reveal Cards In Increasing Order
 */

# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
	// reverse solution
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		std::sort(deck.begin(), deck.end());
		int length = deck.size();
		vector<int> res(length);
		if (length <= 1)
			return deck;
		vector<int> tmp = deckReverse(length, 0);
		for (int i = 0; i < length; i++) {
			res[i] = deck[tmp[i]];
		}
		return res;
	}

	// from start to start+length-1
	vector<int> deckReverse(int length,int start) {
		vector<int> tmp(length);
		if (length <= 2) {
			for (int i = 0; i < length; i++)
				tmp[i] = start + i;
			return tmp;
		}
		if (length == 3) {
			tmp[0] = start;
			tmp[1] = start + 2;
			tmp[2] = start + 1;
			return tmp;
		}
		int middle = length / 2;
		if (length % 2 == 0) {
			for (int i = 0, j = 0; i < length; i += 2, j++) {
				tmp[i] = j + start;
			}
			vector<int> rest = deckReverse(length / 2, start + length / 2);
			for (int i = 1, j = 0; i < length; i += 2, j++) {
				tmp[i] = rest[j];
			}
		}
		else {
			for (int i = 0, j = 0; i < length - 1; i += 2, j++) {
				tmp[i] = j + start;
			}
			vector<int> rest = deckReverse(length / 2 + 1, start + length / 2);
			tmp[length-1] = rest[0];
			for (int i = 1, j = 1; i < length - 1; i += 2, j++) {
				tmp[i] = rest[j];
			}
		}
		return tmp;
	}
};

int main() {
	Solution s;
	int tmp[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int length = 20;
	vector<int> deck;
	for (int i = 0; i < length; i++) {
		deck.push_back(tmp[i]);
	}
	vector<int> res = s.deckRevealedIncreasing(deck);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
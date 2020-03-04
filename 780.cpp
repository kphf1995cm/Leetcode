/*
 *  Author: Peng
 *  Time: 2020-3-4
 *  Problem: 780. Reaching Points
 */

# include<iostream>
using namespace std;

class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (sx < tx&&sy < ty) {
			if (tx < ty) {
				ty = ty%tx;
			}
			if (tx > ty) {
				tx = tx%ty;
			}
		}
		if (sx == tx&&sy <= ty && (ty - sy) % sx == 0)
			return true;
		return sy == ty&&sx <= tx && (tx - sx) % sy == 0;
	}
};

int main() {

}
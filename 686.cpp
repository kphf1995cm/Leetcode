/*
 *  Author: Peng
 *  Time: 2020-3-5
 *  Problem: 686. Repeated String Match
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int min = (B.size() % A.size() == 0) ? B.size() / A.size() : B.size() / A.size() + 1;
		string repeatedA=A;
		for (int i = 1; i < min; i++)
			repeatedA = repeatedA + A;
		if (repeatedA.find(B) != string::npos)
			return min;
		repeatedA = repeatedA + A;
		if (repeatedA.find(B) != string::npos)
			return min+1;
		return -1;

	}
};

int main() {

}
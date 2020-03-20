/*
 *  Author: Peng
 *  Time: 2020-3-7
 *  1201. Ugly Number III
 */

/*
# include<iostream>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n, int a, int b, int c) {
		int minNum = mymin(mymin(a, b), c);
		int maxB = minNum*n;
		int minB = 1;
		while (minB<=maxB)
		{
			int middle = minB + (maxB - minB) / 2;
			int count = nUglyNumber(middle, a, b, c);
			if (count == n)
				return mymax(mymax(middle / a*a, middle / b*b), middle / c*c);
			else {
				if (count < n) {
					minB = middle+1;
				}
				else {
					maxB = middle-1;
				}
			}

		}
		return 0;
	}

	int nUglyNumber(int n,int a,int b,int c) {
		return n / a + n / b + n / c - nv2(n, a, b) - nv2(n, a, c) - nv2(n, b, c) + nv3(n, a, b, c);
	}
	
	int nv3(int n, int a, int b, int c) {
		int gbsab = (a / gcd(a, b))*b;
		int gbsabc = (gbsab / gcd(gbsab, c))*c;
		return n / gbsabc;
	}

	int nv2(int n, int a, int b) {
		int gbs = (a / gcd(a, b))*b;
		return n / gbs;
	}

	int gcd( int a,  int b) {
		return b == 0 ? a : gcd(b, a%b);
	}

	int mymax(int a, int b) {
		return a > b ? a : b;
	}

	int mymin(int a, int b) {
		return a < b ? a : b;
	}
};

int main() {
	Solution s;
	cout<<s.nthUglyNumber(1000000000,2,217983653,336916467)<<endl;
	return 0;
}*/
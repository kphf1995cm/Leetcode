/*
 *  Author: Peng
 *  Time: 2020-2-12
 *  Problem: 166. Fraction to Recurring Decimal
 */

# include<iostream>
# include<string>
# include<math.h>
# include<unordered_map>
using namespace std;

class Solution {
public: 
	string fractionToDecimal(int numerato, int denominato) {
		string res;
		bool flag = false;
		if(numerato>0&&denominato<0 ||numerato<0&&denominato>0)
			flag = true;
		long numerator = abs(long(numerato));
		long denominator = abs(long(denominato));
		long integer=numerator/denominator;
		long decimal=numerator-integer*denominator;
		if (integer == 0) {
			res.insert(res.begin(),'0');
		}
		else {
			while (integer) {
				res.insert(res.begin(),integer % 10 + '0');
				integer /= 10;
			}
		}
		if (decimal != 0) {
			res.insert(res.end(), '.');
			string decimalStr;
			unordered_map<long, int> remainder;
			while (decimal != 0) {
				if (remainder.count(decimal) == 0) {
					decimal *= 10;
					char tmp = decimal / denominator + '0';
					remainder[decimal / 10] = decimalStr.size();
					decimalStr.insert(decimalStr.end(), tmp);
					decimal = decimal - decimal / denominator*denominator;
				}
				else {
					decimalStr.insert((size_t)(remainder[decimal]), 1,'(');
					decimalStr.insert(decimalStr.end(), ')');
					break;
				}
			}
			res.insert(res.size(), decimalStr);
		}
		if (flag)
			res.insert(res.begin(),'-');
		return res;
	}

};

int main() {
	//cout << INT_MIN << endl;
	Solution s;
	int numerator,denominator;
	while(cin >> numerator >> denominator)
		cout << s.fractionToDecimal(numerator, denominator)<<endl;
	return 0;
}

// longest common prefix
// 2019-1-20
// kuangpeng kphf1995cm@outlook.com



#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string commonStr;
		int pos = 0;
		char c;
		bool end = false;
		if (commonStr.size() == 0)
			return commonStr;
		while (true)
		{
			if (pos < strs[0].size())
				c = strs[0][pos];
			else
				break;
			for (size_t i = 1; i < strs.size(); i++)
			{
				if (pos < strs[i].size()&& strs[i][pos] == c)
					continue;
				else
				{
					end = true;
					break;
				}
			}
			if (end == true)
				break;
			commonStr.insert(commonStr.end(), c);
			pos++;
		}
		return commonStr;
	}
};

void test()
{
	Solution s;
	vector<string> strs;
	//strs.push_back("flower");
	//strs.push_back("flow");
	//strs.push_back("");
	cout << s.longestCommonPrefix(strs);
}

int main()
{
	test();
	return 0;
}


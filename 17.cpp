
# include<iostream>
# include<vector>
# include<string>
using namespace std;

class Solution {
public:
	vector<vector<char>> digitMapLetters;
	void init()
	{
		string letters[] = { "", "", "abc", "def",
			"ghi","jkl","mno",
			"pqrs","tuv","wxyz"};
		for (size_t i=0; i < 10; i++)
		{
			vector<char> str;
			for (size_t j = 0; j < letters[i].size(); j++)
				str.push_back(letters[i][j]);
			digitMapLetters.push_back(str);
		}
		//for (size_t i = 2; i < 10; i++)
		//{
		//	for (size_t j = 0; j < digitMapLetters[i].size(); j++)
		//		cout << digitMapLetters[i][j];
		//	cout << endl;
		// }
	}
	void parse(vector<string> &res,string frontLevelStr,string &digits,int curLevel,int dstLevel)
	{
		int number = digits[curLevel] - '0';
		if (curLevel == dstLevel)
		{
			for (size_t i = 0; i < digitMapLetters[number].size(); i++)
				res.push_back(frontLevelStr + digitMapLetters[number][i]);
		}
		else
		{
			for (size_t i = 0; i < digitMapLetters[number].size(); i++)
			{
				parse(res, frontLevelStr + digitMapLetters[number][i], digits, curLevel + 1, dstLevel);
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.size() == 0)
			return res;
		init();
		parse(res, "", digits, 0, digits.size() - 1);
		return res;
	}
};

void test()
{
	Solution s;
	vector<string> res=s.letterCombinations("");
	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}

int main()
{
	test();
	return 0;
}

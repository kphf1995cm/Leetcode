# include<iostream>
# include<vector>
# include<math.h>
using namespace std;

int const LevelSum = 10;

int getSum(int n) {
	return 26 * (pow(26, n) -1)/ 25;
}

int getLevel(int number) {
	if (number <= 26)
		return 1;
	int minLevel = 1;
	int maxLevel = LevelSum;
	int midLevel = (minLevel + maxLevel) / 2;
	while (true) {
		int sum = getSum(midLevel);
		if (number <= sum)
			maxLevel = midLevel;
		else
			minLevel = midLevel;
		if (maxLevel-minLevel<=1)
			return maxLevel;
		midLevel = (minLevel + maxLevel) / 2;
	}
}

int main() {
	vector<int> childPos;
	int number;
	cin >> number;
	int belongLevel = getLevel(number);
	cout << "belongLevel:"<<belongLevel<<endl;
	int pos = number - getSum(belongLevel - 1);
	while (belongLevel>=1){
		belongLevel--;
		if(pos%26==0)
			childPos.push_back(26);
		else
			childPos.push_back(pos % 26);
		pos = pos / 26+1;
	}
	for (int i = childPos.size() - 1; i >= 0; i--)
		cout <<  char('a'+childPos[i]-1)<< " ";
}


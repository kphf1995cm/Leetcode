/*
 *  Author: Peng
 *  Time: 2020-3-18
 *  Problem: 1122. Relative Sort Array
 */

# include<iostream>
# include<vector>
# include<time.h>
# include<unordered_map>
# include<algorithm>
using namespace std;

void ksort(vector<int>& vals) {
	if (vals.size() > 0) {
		for (int i = 0; i < vals.size(); i++) {
			int k = i,j;
			for (j = i + 1; j < vals.size(); j++) {
				if (vals[j] < vals[k])
					k = j;
			}
			if (k != i) {
				int temp = vals[k];
				vals[k] = vals[i];
				vals[i] = temp;
			}
		}
	}
}

void pipesort(vector<int>& vals) {
	if (vals.size()>0) {
		for (int i = vals.size() - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (vals[j] > vals[j + 1]) {
					int temp = vals[j + 1];
					vals[j + 1] = vals[j];
					vals[j] = temp;
				}
			}
		}
	}
}

void testSort() {
	vector<int> vals;
	for (auto i = 0; i < 20; i++)
		vals.push_back(rand() % 20);
	pipesort(vals);
	for (auto i = 0; i < vals.size(); i++) {
		cout << vals[i] << " ";
	}
	cout << endl;
}

struct ValPos {
	int val;
	int pos;
	ValPos(int v,int p) {
		val = v;
		pos = p;
	}
};

bool cmp(const ValPos& v1, const ValPos& v2) {
	return v1.pos < v2.pos;
}

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_map<int, int> valueIndex;	
		for (int i = 0; i < arr2.size(); i++) {
			valueIndex[arr2[i]] = i;
		}
		vector<ValPos> left;
		vector<int> right;
		for (int i = 0; i < arr1.size(); i++) {
			if (valueIndex.count(arr1[i]) == 0)
				right.push_back(arr1[i]);
			else
				left.push_back(ValPos(arr1[i],valueIndex[arr1[i]]));
		}
		sort(left.begin(), left.end(), cmp);
		sort(right.begin(), right.end());
		vector<int> res;
		for (int i = 0; i < left.size(); i++)
			res.push_back(left[i].val);
		for (int i = 0; i < right.size(); i++)
			res.push_back(right[i]);
		return res;
	}
};

int main() {
	Solution s;
}
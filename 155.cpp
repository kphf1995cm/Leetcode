/*
 *  Author: Peng
 *  Time: 2020-3-20
 *  155. Min Stack
 */

# include<iostream>
# include<vector>
using namespace std;

struct ValMin
{
	int val;
	int min;
	ValMin(int v,int m) {
		val = v;
		min = m;
	}
	ValMin() {
		val = 0;
		min = 0;
	}
};
class MinStack {
public:
	/** initialize your data structure here. */
	int minimum;
	vector<ValMin> vals;
	int index;
	MinStack() {
		index = 0;
		minimum = INT_MAX;
		vals.resize(10);
	}

	void push(int x) {
		if (x < minimum)
			minimum = x;
		if (index >= vals.size())
			vals.resize(2 * index);
		vals[index++] = ValMin(x,minimum);
	}

	void pop() {
		index--;
		if (index > 0) {
			if (minimum < vals[index - 1].min)
				minimum = vals[index - 1].min;
		}
		else {
			minimum = INT_MAX;
		}
	}

	int top() {
		return vals[index - 1].val;
	}

	int getMin() {
		return vals[index - 1].min;
	}
};

int main() {
	MinStack ms;
}
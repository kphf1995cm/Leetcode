/*
 *  Author: Peng
 *  Time: 2020-2-12
 *  Problem: 895. Maximum Frequency Stack
 */

# include<iostream>
# include<math.h>
# include<unordered_map>
# include<stack>
using namespace std;

class FreqStack {
public:
	unordered_map<int, int> valueCount;
	unordered_map<int, stack<int>> frequencyValueStack;
	int curFrequency;
	FreqStack() {
		curFrequency = 0;
	}

	void push(int x) {
		valueCount[x]++;
		int freq = valueCount[x];
		if (curFrequency < freq)
			curFrequency = freq;
		if (frequencyValueStack.count(freq) == 0) {
			stack<int> temp;
			temp.push(x);
			frequencyValueStack[freq] = temp;
		}
		else {
			frequencyValueStack[freq].push(x);
		}
	}

	int pop() {
		int res = frequencyValueStack[curFrequency].top();
		valueCount[res]--;
		frequencyValueStack[curFrequency].pop();
		if (frequencyValueStack[curFrequency].empty()) {
			frequencyValueStack.erase(curFrequency);
			curFrequency--;
		}
		return res;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main() {
	return 0;
}




/*
#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>

using namespace std;

struct node {
	int processNum; // from 1
	int execPos; // from 0, to execute
};


int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> processStatement(n+1);
	int temp;
	for (int i = 1; i <= n; i++) {
		while (cin >> temp){
			processStatement[i].push_back(temp);
			char c = cin.get();
			if (c == '\n')
				break;
		}
	}
	stack<node> callStack;
	callStack.push(node{ k,0 });
	unordered_set<int> processInStack;
	processInStack.insert(k);
	bool cannotReturn = false;
	while (callStack.empty() == false) {
		int curProcessNum = callStack.top().processNum;
		int execPos = callStack.top().execPos;
		int statement;
		if(execPos<processStatement[curProcessNum].size())
			statement = processStatement[curProcessNum][callStack.top().execPos];
		else {
			cannotReturn = true;
			break;
		}
		if (statement == -1)
			break;
		if (statement == 0) {
			callStack.pop();
			processInStack.erase(curProcessNum);
		}else {
			if (processInStack.count(statement) > 0) {
				cannotReturn = true;
				break;
			}
			else {
				callStack.top().execPos += 1;
				processInStack.insert(statement);
				callStack.push(node{ statement,0 });
			}
		}

	}
	if (cannotReturn == true)
		cout << "E" << endl;
	else {
		if (callStack.empty() == true)
			cout << "R" << endl;
		else {
			while (callStack.empty() != true) {
				cout << callStack.top().processNum << " ";
				callStack.pop();
			}
		}
	}
	return 0;
}
*/
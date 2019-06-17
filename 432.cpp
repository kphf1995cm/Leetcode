#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

class AllOne {
private:
	unordered_map<string, int> keyCount;
	map<int, vector<string>> countKeys;
public:
	/** Initialize your data structure here. */
	AllOne() {
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		// remove
		if (keyCount.count(key) != 0)
		{
			int preNum = keyCount[key];
			for (vector<string>::iterator iter = countKeys[preNum].begin(); iter != countKeys[preNum].end(); iter++) {
				if (*iter==key) {
					countKeys[preNum].erase(iter);
					if (countKeys[preNum].size() == 0)
						countKeys.erase(preNum);
					break;
				}
			}
		}
		// add
		keyCount[key]++;
		int num = keyCount[key];
		if (countKeys.count(num) == 0) 
			countKeys[num] = vector<string>();
		countKeys[num].push_back(key);
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (keyCount.count(key) > 0) {
			// remove
			int preNum = keyCount[key];
			for (vector<string>::iterator iter = countKeys[preNum].begin(); iter != countKeys[preNum].end(); iter++) {
				if (*iter == key) {
					countKeys[preNum].erase(iter);
					if (countKeys[preNum].size() == 0)
						countKeys.erase(preNum);
					break;
				}
			}
			// add
			keyCount[key]--;
			if (keyCount[key] == 0)
				keyCount.erase(key);
			else {
				int num = keyCount[key];
				if (countKeys.count(num) == 0)
					countKeys[num] = vector<string>();
				countKeys[num].push_back(key);
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (countKeys.size() == 0)
			return "";
		map<int, vector<string>>::reverse_iterator iter = countKeys.rbegin();
		return iter->second[0];
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (countKeys.size() == 0)
			return "";
		map<int, vector<string>>::iterator iter = countKeys.begin();
		return iter->second[0];
	}
};

int main() {
	string key = "test";
	AllOne* obj = new AllOne();
	obj->inc(key);
	string param_3 = obj->getMaxKey();
	cout << param_3 << " ";
	obj->dec(key);
	string param_4 = obj->getMinKey();
	cout << param_4 << " ";
	return 0;
}

/**
* Your AllOne object will be instantiated and called as such:
* AllOne* obj = new AllOne();
* obj->inc(key);
* obj->dec(key);
* string param_3 = obj->getMaxKey();
* string param_4 = obj->getMinKey();
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<time.h>
using namespace std;

struct Node {
	int val;
	int index;
	Node(int v,int i) {
		val = v;
		index = i;
	}
};

class RandomizedCollection {

private:
	unordered_map<int, vector<Node>> valCount;
	unordered_map<int, int> indexVal;
	int index;

public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		index = 0;
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool res=false;
		if (valCount.count(val) == 0) { 
			res = true;
		}
		valCount[val].push_back(Node(val,index));
		indexVal[index++] = val;
		return res;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		bool res = false;
		if (valCount.count(val) != 0) {
			res = true;
			int valIndex = valCount[val][valCount[val].size() - 1].index;
			valCount[val].erase(valCount[val].end()-1);
			if (valCount[val].size() == 0)
				valCount.erase(val);
			indexVal.erase(valIndex);
		}
		return res;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		int randomIndex = rand() % index;
		while(indexVal.count(randomIndex)==0)
			randomIndex = rand() % index;
		return indexVal[randomIndex];
	}
};

int main() {

	RandomizedCollection r;
	const int size = 100;
	for (int i = 0; i < size; i++)
		cout<<r.insert(rand() % size)<<" ";
	for (int i = 0; i < size/2; i++)
		cout<<r.remove(rand() % size)<<" ";
	for (int i = 0; i < size; i++)
		cout << r.getRandom() << " ";
	return 0;
}
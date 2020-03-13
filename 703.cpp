/*
 *  Author: Peng
 *  Time: 2020-3-12
 *  Problem: 703. Kth Largest Element in a Stream
 */

# include<iostream>
# include<vector>
# include<queue>
using namespace std;

class heap {
public:
	int size;
	vector<int> vals;
	int capacity;
	heap(int c) { 
		capacity = c;
		vals.resize(capacity);
		vals[0] = INT_MAX;
		size = 1;
	}
	void insert(int v) {
		if (size < capacity) {
			vals[size] = v;
			siftUp(size);
			size++;
		}
	}
	int getHeap() {
		int res = vals[1];
		size--;
		vals[1] = vals[size];
		siftDown();
		return res;
	}

	void siftUp(int i) {
		while (vals[i]>vals[i/2]) {
			int temp = vals[i/2];
			vals[i/2] = vals[i];
			vals[i] = temp;
			i = i / 2;
		}
	}

	void siftDown() {
		int i = 1;
		int k=i*2;
		while (k < size) {
			if (k + 1 < size) {
				if (vals[k + 1] > vals[k]){
					k = k + 1;
				}
			}
			if (vals[i]>vals[k])
				break;
			int temp = vals[k];
			vals[k] = vals[i];
			vals[i] = temp;
			i = k;
			k = 2 * i;
		}
	}
};

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

class KthLargest {
public:
	priority_queue<int, vector<int>, cmp> minHeap;
	int kth;
	KthLargest(int k, vector<int>& nums) {
		kth = k;
		for (size_t i = 0; i < nums.size(); i++) {
			minHeap.push(nums[i]);
		}
		while (minHeap.size() > k)
			minHeap.pop();
	}

	int add(int val) {
		if (minHeap.size() >= kth) {
			if (minHeap.top() >= val)
				return minHeap.top();
			else {
				minHeap.pop();
				minHeap.push(val);
				return minHeap.top();
			}
		}
		else {
			minHeap.push(val);
			return minHeap.top();
		}
	}
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest* obj = new KthLargest(k, nums);
* int param_1 = obj->add(val);
*/

int main() {
	int v[10] = { 7,4,6,3,2,8,1,9,6,7 };
	heap h(20);
	for (int i = 0; i < 10; i++) {
		h.insert(v[i]);
	}
	while (h.size != 1) {
		cout << h.getHeap() << " "<<h.size<<endl;
	}
	return 0;
}



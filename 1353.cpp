/*
 *  Author: Peng
 *  Time: 2020-3-21
 *  1353. Maximum Number of Events That Can Be Attended
 */

# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_set>
using namespace std;

struct event {
	int start;
	int end;
	event(int s,int e) {
		start = s;
		end = e;
	}
};

bool cmp(event e1, event e2) {
	return e1.end < e2.end;
}

class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		vector<event> eventList;
		for (int i = 0; i < events.size(); i++) {
			eventList.push_back(event(events[i][0], events[i][1]));
		}
		sort(eventList.begin(), eventList.end(), cmp);
		unordered_set<int> occupyDay;
		int totalEvents = 0;
		for (int i = 0; i < eventList.size(); i++) {
			for (int s = eventList[i].start; s <= eventList[i].end; s++) {
				if (occupyDay.count(s) == 0) {
					totalEvents++;
					occupyDay.insert(s);
					break;
				}
			}
		}
		return totalEvents;
	}
};

int main() {
	Solution s;

}

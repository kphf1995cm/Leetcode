/*
 *  Author: Peng
 *  Time: 2020-3-20
 *  207. Course Schedule
 */

# include<iostream>
# include<vector>
# include<queue>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> relyCourseNum(numCourses);
		vector<vector<int>> childCourses(numCourses);
		queue<int> noRelyCourses;
		for (int i = 0; i < prerequisites.size(); i++) {
			relyCourseNum[prerequisites[i][0]]++;
			childCourses[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		for (int i = 0; i < relyCourseNum.size(); i++) {
			if (relyCourseNum[i] == 0)
				noRelyCourses.push(i);
		}
		int sortNum = 0;
		while (noRelyCourses.empty()==false) {
			int index = noRelyCourses.front();
			noRelyCourses.pop();
			sortNum++;
			for (int i = 0; i < childCourses[index].size(); i++) {
				int child = childCourses[index][i];
				relyCourseNum[child]--;
				if (relyCourseNum[child] == 0)
					noRelyCourses.push(child);
			}
		}
		return sortNum == numCourses;
	}
};

int main() {
	return 0;
}


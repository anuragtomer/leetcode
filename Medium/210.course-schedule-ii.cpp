#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for (auto pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        vector<int> que;
        vector<int> order;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                que.push_back(i);
            }
        }
        int i = 0;
        while (i < que.size()) {
            int freeCourse = que[i];
            ++i;
            order.push_back(freeCourse);
            for (auto neigh : edges[freeCourse]) {
                --inDegree[neigh];
                if (inDegree[neigh] == 0) {
                    que.push_back(neigh);
                }
            }
        }
        return que.size() == numCourses ? order : vector<int>();
    }
};

int main() {
    Solution sol;

    return 0;
}


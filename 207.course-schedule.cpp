#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> nodes(numCourses);
        vector<int> inDegree(numCourses, 0), zeroInDegree;
        for (auto pre : prerequisites) {
            nodes[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push_back(i);
            }
        }

        for (int i = 0; i < zeroInDegree.size(); ++i) {
            for (auto node : nodes[zeroInDegree[i]]) {
                --inDegree[node];
                if (inDegree[node] == 0) {
                    zeroInDegree.push_back(node);
                }
            }
        }
        return zeroInDegree.size() == numCourses;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> pre = {{1, 0}};
    assert(sol.canFinish(2, pre));
    return 0;
}

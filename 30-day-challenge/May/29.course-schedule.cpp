#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    bool dfs(int starting, vector<int> &seen) {
        if (seen[starting] == 1)
            return false;
        if (seen[starting] == 2)
            return true;
        seen[starting] = 1;
        for (auto nei : neighbors[starting]) {
            if (!dfs(nei, seen))
                return false;
        }
        seen[starting] = 2;
        return true;
    }
    vector<vector<int>> neighbors;

   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        neighbors.clear();
        neighbors.resize(numCourses);
        for (auto edges : prerequisites) {
            neighbors[edges[0]].push_back(edges[1]);
        }
        vector<int> seen(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, seen)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    assert(true == sol.canFinish(numCourses, prerequisites));
    prerequisites = {{1, 0}, {0, 1}};
    assert(false == sol.canFinish(numCourses, prerequisites));
    numCourses = 7;
    prerequisites = {{2, 4}, {3, 5}, {1, 2}, {0, 2}, {5, 6}, {2, 3}, {4, 5}, {6, 2}};
    assert(false == sol.canFinish(numCourses, prerequisites));
    prerequisites = {{2, 4}, {3, 5}, {1, 2}, {0, 2}, {5, 6}, {2, 3}, {4, 5}};
    assert(true == sol.canFinish(numCourses, prerequisites));
    numCourses = 4;
    prerequisites = {{2, 0}, {1, 0}, {3, 1}, {3, 2}, {1, 3}};
    assert(false == sol.canFinish(numCourses, prerequisites));
    return 0;
}

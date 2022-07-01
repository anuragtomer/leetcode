#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            int mgr = manager[i];
            if (mgr != -1) {
                edges[mgr].push_back(i);
            }
        }
        queue<pair<int, int>> bfsq;
        bfsq.push({headID, informTime[headID]});
        int maxInformTime = 0;
        while (!bfsq.empty()) {
            auto [emp, time] = bfsq.front();
            bfsq.pop();
            maxInformTime = max(maxInformTime, time);
            for (auto neigh : edges[emp]) {
                bfsq.push({neigh, time + informTime[neigh]});
            }
        }
        return maxInformTime;
    }
};

int main() {
    Solution sol;

    return 0;
}


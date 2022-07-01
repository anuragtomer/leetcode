#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int timeToFlowerTree(vector<int> &father, vector<int> &time) {
        vector<vector<int>> edges(father.size());
        int i = 0;
        for (auto f : father) {
            if (f != -1)
                edges[f].push_back(i);
            ++i;
        }
        int cost = 0;
        queue<pair<int, int>> bfsQ;
        bfsQ.push({0, 0});
        while (bfsQ.empty() == false) {
            int node = bfsQ.front().first;
            int currentTime = bfsQ.front().second;
            bfsQ.pop();
            cost = max(cost, currentTime);
            for (auto neigh : edges[node])
                bfsQ.push({neigh, time[neigh] + currentTime});
        }
        return cost;
    }
};

int main() {
    Solution sol;

    return 0;
}


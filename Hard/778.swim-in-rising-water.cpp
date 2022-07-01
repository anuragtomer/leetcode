#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int swimInWater(vector<vector<int>> &grid) {
        struct data {
            int val;
            int i;
            int j;
        };
        auto comp = [](data &a, data &b) { return a.val > b.val; };
        priority_queue<data, vector<data>, decltype(comp)> pq(comp);
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = grid.size();
        pq.push({grid[0][0], 0, 0});
        int currentTime = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<bool>> visiting(n, vector<bool>(n, false));
        visited[0][0] = true;
        visiting[0][0] = true;
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().val <= currentTime) {
                auto [val, i, j] = pq.top();
                visited[i][j] = true;
                pq.pop();
                for (auto dir : direction) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] || visiting[x][y])
                        continue;
                    visiting[x][y] = true;
                    pq.push({grid[x][y], x, y});
                }
            }
            if (visited[n - 1][n - 1])
                return currentTime;
            currentTime = pq.empty() ? -1 : pq.top().val;
        }
        return currentTime;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    assert(3 == sol.swimInWater(grid));
    return 0;
}


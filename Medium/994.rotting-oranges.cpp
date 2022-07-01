#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> bfs;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 2)
                    bfs.push({i, j});
        int time = 0;
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!bfs.empty()) {
            int len = bfs.size();
            while (len) {
                --len;
                auto [i, j] = bfs.front();
                bfs.pop();
                grid[i][j] = 2;
                for (auto dir : direction) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    bfs.push({x, y});
                }
            }
            ++time;
        }
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    return -1;
        return max(0, time - 1);
    }
};

int main() {
    Solution sol;

    return 0;
}


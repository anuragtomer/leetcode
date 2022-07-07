#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int dfs(vector<vector<int>> &grid, int i, int j) {
        int count = 0;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto dir : direction) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
                continue;
            grid[x][y] = 0;
            count += 1 + dfs(grid, x, y);
        }
        return count;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxArea = 0;
        for (int i = 0, n = grid.size(); i < n; ++i) {
            for (int j = 0, m = grid[i].size(); j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    maxArea = max(maxArea, 1 + dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    assert(6 == sol.maxAreaOfIsland(grid));
    return 0;
}


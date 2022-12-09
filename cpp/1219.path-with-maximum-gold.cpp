#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int dfs(vector<vector<int>> &grid, int i, int j, int H, int W) {
    int maxGold = 0;
    int original = grid[i][j];
    grid[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
      int x = i + dir[k][0], y = j + dir[k][1];
      if (x < 0 || y < 0 || x >= H || y >= W || grid[x][y] == 0)
        continue;
      maxGold = max(maxGold, dfs(grid, x, y, H, W));
    }
    grid[i][j] = original;
    return original + maxGold;
  }

 public:
  int getMaximumGold(vector<vector<int>> &grid) {
    int H = grid.size();
    if (H == 0)
      return 0;
    int W = grid[0].size();
    int maxGold = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] != 0)
          maxGold = max(maxGold, dfs(grid, i, j, H, W));
      }
    }
    return maxGold;
  }
};

int main() {
  Solution sol;

  return 0;
}


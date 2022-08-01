#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePaths(int W, int H) {
    vector<vector<int>> dp(H, vector<int>(W, 1));
    for (int i = H - 2; i >= 0; --i) {
      for (int j = W - 2; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[0][0];
  }
};
// Another Solution
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    grid[0][0] = 1;
    queue<pair<int, int>> queue;
    queue.push({0, 0});
    vector<vector<int>> direction = {{0, 1}, {1, 0}};
    while (!queue.empty()) {
      auto [i, j] = queue.front();
      queue.pop();
      for (auto &dir : direction) {
        int x = i + dir[0], y = j + dir[1];
        if (x >= m || y >= n)
          continue;
        if (grid[x][y] == 0)
          queue.push({x, y});
        grid[x][y] += grid[i][j];
      }
    }
    return grid[m - 1][n - 1];
  }
};
int main() {
  Solution sol;
  assert(28 == sol.uniquePaths(7, 3));
  assert(3 == sol.uniquePaths(3, 2));
  return 0;
}

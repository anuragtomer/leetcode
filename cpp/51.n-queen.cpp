#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  bool canPlace(int row, int col, int n, const vector<string> &grid) {
    // Same Row
    for (int i = 0; i < n; ++i) {
      if (grid[i][col] == 'Q') {
        return false;
      }
    }
    // Same col
    for (int j = 0; j < n; ++j) {
      if (grid[row][j] == 'Q') {
        return false;
      }
    }
    // Diagonal
    for (int i = 0; row - i >= 0 && col - i >= 0; ++i) {
      if (grid[row - i][col - i] == 'Q') {
        return false;
      }
    }
    for (int i = 0; row + i < n && col + i < n; ++i) {
      if (grid[row + i][col + i] == 'Q') {
        return false;
      }
    }
    // Alternate Diagonal
    for (int i = 0; row - i >= 0 && col + i < n; ++i) {
      if (grid[row - i][col + i] == 'Q') {
        return false;
      }
    }
    for (int i = 0; row + i < n && col - i >= 0; ++i) {
      if (grid[row + i][col - i] == 'Q') {
        return false;
      }
    }
    return true;
  }
  void dfs(int n, int row, vector<string> &grid,
           vector<vector<string>> &result) {
    if (row == n) {
      result.push_back(grid);
      return;
    }
    for (int j = 0; j < n; ++j) {
      if (canPlace(row, j, n, grid)) {
        grid[row][j] = 'Q';
        dfs(n, row + 1, grid, result);
        grid[row][j] = '.';
      }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> grid(n);
    for (string &g : grid) {
      g = string(n, '.');
    }
    vector<vector<string>> result;
    dfs(n, 0, grid, result);
    return result;
  }
};

int main() {
  auto lMatch = [](vector<vector<string>> &exp,
                   vector<vector<string>> out) -> bool {
    if (out.size() != exp.size())
      return false;
    sort(exp.begin(), exp.end());
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); ++i) {
      if (out[i].size() != exp[i].size())
        return false;
      for (int j = 0; j < out[i].size(); ++j)
        if (out[i][j] != exp[i][j])
          return false;
    }
    return true;
  };
  Solution sol;
  int n = 4;
  vector<vector<string>> expected = {{".Q..", "...Q", "Q...", "..Q."},
                                     {"..Q.", "Q...", "...Q", ".Q.."}};
  assert(lMatch(expected, sol.solveNQueens(n)));

  n = 1, expected = {{"Q"}};
  assert(lMatch(expected, sol.solveNQueens(n)));

  n = 2, expected = {};
  assert(lMatch(expected, sol.solveNQueens(n)));
  return 0;
}


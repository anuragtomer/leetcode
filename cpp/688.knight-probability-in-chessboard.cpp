#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  double grid[26][26][101];

  double knightProbability(int n, int k, int row, int column) {
    if (row >= n || column >= n || row < 0 || column < 0)
      return 0; // out of bounds
    if (k == 0)
      return 1; // no more moves needed
    if (grid[row][column][k] > 0)
      return grid[row][column][k];

    double result = 0;
    result += 0.125 * knightProbability(n, k - 1, row - 1, column - 2);
    result += 0.125 * knightProbability(n, k - 1, row - 1, column + 2);
    result += 0.125 * knightProbability(n, k - 1, row + 1, column - 2);
    result += 0.125 * knightProbability(n, k - 1, row + 1, column + 2);
    result += 0.125 * knightProbability(n, k - 1, row - 2, column - 1);
    result += 0.125 * knightProbability(n, k - 1, row - 2, column + 1);
    result += 0.125 * knightProbability(n, k - 1, row + 2, column - 1);
    result += 0.125 * knightProbability(n, k - 1, row + 2, column + 1);

    grid[row][column][k] = result; // mark as visited

    return result;
  }
  double knightProbabilityBFS(int n, int k, int row, int column) {
    vector<vector<double>> board(n, vector<double>(n, 0.0)),
      next_board(n, vector<double>(n, 0.0));
    board[row][column] = 1.0;
    vector<vector<int>> next_positions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                          {1, -2},  {1, 2},  {2, -1},  {2, 1}};
    while (k) {
      --k;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int l = 0; l < 8; ++l) {
            int x = i + next_positions[l][0], y = j + next_positions[l][1];
            if (x < 0 || y < 0 || x >= n || y >= n)
              continue;
            next_board[x][y] += 0.125 * board[i][j];
          }
        }
      }
      board = next_board;
      next_board = vector<vector<double>>(n, vector<double>(n, 0.0));
    }
    double sum = 0.0;
    for (auto row : board)
      for (auto val : row)
        sum += val;
    return sum;
  }
};
int main() {
  Solution sol;
  assert(sol.knightProbability(3, 2, 0, 0) == 0.0625);
  assert(sol.knightProbability(1, 0, 0, 0) == 1);
  return 0;
}

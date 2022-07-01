#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool markCells(vector<vector<int>> &board) {
    int H = board.size(), W = board[0].size();
    bool found = false;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (board[i][j] == 0)
          continue;
        if (j + 2 < W && abs(board[i][j + 1]) == abs(board[i][j]) && abs(board[i][j + 2]) == abs(board[i][j])) {
          found = true;
          for (int k = j; k < W && abs(board[i][k]) == abs(board[i][j]); ++k)
            board[i][k] = -abs(board[i][k]);
        }
        if (i + 2 < H && abs(board[i][j]) == abs(board[i + 1][j]) && abs(board[i][j]) == abs(board[i + 2][j])) {
          found = true;
          for (int k = i; k < H && abs(board[k][j]) == abs(board[i][j]); ++k)
            board[k][j] = -abs(board[k][j]);
        }
      }
    }
    return found;
  }
  void dropCells(vector<vector<int>> &board) {
    int H = board.size(), W = board[0].size();
    for (int j = 0; j < W; ++j) {
      int idx = H - 1;
      for (int i = H - 1; i >= 0; --i) {
        if (board[i][j] > 0) {
          board[idx][j] = board[i][j];
          --idx;
        }
      }
      while (idx >= 0) {
        board[idx][j] = 0;
        --idx;
      }
    }
  }
  vector<vector<int>> candyCrush(vector<vector<int>> &board) {
    if (board.empty())
      return board;
    bool changed = true;
    while (changed) {
      changed = markCells(board);
      if (changed) {
        dropCells(board);
      }
    }
    return board;
  }
};

int main() {
  Solution sol;

  return 0;
}


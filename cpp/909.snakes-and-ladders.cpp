#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  void lineariseBoard(vector<vector<int>> &board, vector<int> *linear_board) {
    bool rev = false;
    linear_board->push_back(0);
    for (auto row_it = board.rbegin(); row_it != board.rend();
         row_it = next(row_it)) {
      if (rev) {
        for (auto val_it = row_it->rbegin(); val_it != row_it->rend();
             val_it = next(val_it)) {
          linear_board->push_back(*val_it);
        }
      } else {
        for (auto val_it = row_it->begin(); val_it != row_it->end();
             val_it = next(val_it)) {
          linear_board->push_back(*val_it);
        }
      }
      rev = !rev;
    }
  }
  void bfs(vector<int> &board, vector<int> &min_steps) {
    struct data {
      int idx;
      int steps;
    };
    queue<data> bfsq;
    unordered_set<int> visited;
    bfsq.push({1, 0});
    int N = board.size();
    while (not bfsq.empty()) {
      auto [idx, steps] = bfsq.front();
      steps += 1;
      bfsq.pop();
      for (int i = idx + 1; i < min(idx + 7, N); ++i) {
        if (board[i] == -1 && min_steps[i] > steps) {
          bfsq.push({i, steps});
          min_steps[i] = steps;
        }
        if (board[i] != -1 && min_steps[board[i]] > steps) {
          bfsq.push({board[i], steps});
          min_steps[board[i]] = steps;
        }
      }
    }
  }

 public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int H = board.size();
    if (H == 0)
      return 0;
    int W = board[0].size();
    if (H * W <= 6) {
      return 1;
    }
    vector<int> linear_board;
    linear_board.reserve(H * W + 1);
    lineariseBoard(board, &linear_board);
    vector<int> min_steps(H * W + 1, INT_MAX);
    min_steps[1] = 0;
    bfs(linear_board, min_steps);
    return min_steps[H * W] == INT_MAX ? -1 : min_steps[H * W];
  }
};
int main() {
  Solution sol;
  vector<vector<int>> board = {
    {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
    {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  assert(4 == sol.snakesAndLadders(board));
  board = {{-1, -1}, {-1, 3}};
  assert(1 == sol.snakesAndLadders(board));
  board = {{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
  assert(-1 == sol.snakesAndLadders(board));
  board = {{-1, 1, 2, -1}, {2, 13, 15, -1}, {-1, 10, -1, -1}, {-1, 6, 2, 8}};
  assert(2 == sol.snakesAndLadders(board));
  return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> perfectBoard = {{1, 2, 3}, {4, 5, 0}};
  bool boardMatches(vector<vector<int>> &board) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j)
        if (board[i][j] != perfectBoard[i][j])
          return false;
    }
    return true;
  }
  int getIntBoard(vector<vector<int>> &board) {
    int num = 0;
    num = board[1][2] + board[1][1] * 10 + board[1][0] * 100 + board[0][2] * 1000 + board[0][1] * 10000 +
          board[0][0] * 100000;
    return num;
  }
  template <typename T>
  void printBoard(T &board) {
    for (auto row : board) {
      for (auto val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    unordered_set<int> visited;
    queue<vector<vector<int>>> bfsQ;
    bfsQ.push(board);
    int steps = 0;
    vector<vector<int>> direction = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    while (!bfsQ.empty()) {
      int len = bfsQ.size();
      while (len) {
        --len;
        board = bfsQ.front();
        bfsQ.pop();
        if (boardMatches(board))
          return steps;
        if (visited.find(getIntBoard(board)) != visited.end())
          continue;
        visited.insert(getIntBoard(board));
        bool foundZero = false;
        for (int i = 0; i < 2 && !foundZero; ++i) {
          for (int j = 0; j < 3 && !foundZero; ++j) {
            if (board[i][j] == 0) {
              foundZero = true;
              for (auto dir : direction) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || y < 0 || x >= 2 || y >= 3)
                  continue;
                swap(board[i][j], board[x][y]);
                if (visited.count(getIntBoard(board))) {
                  swap(board[i][j], board[x][y]);
                  continue;
                }
                bfsQ.push(board);
                swap(board[i][j], board[x][y]);
              }
            }
          }
        }
      }
      ++steps;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
  assert(1 == sol.slidingPuzzle(board));
  board = {{1, 2, 3}, {5, 4, 0}};
  assert(-1 == sol.slidingPuzzle(board));
  board = {{4, 1, 2}, {5, 0, 3}};
  assert(5 == sol.slidingPuzzle(board));
  board = {{3, 2, 4}, {1, 5, 0}};
  assert(14 == sol.slidingPuzzle(board));
  return 0;
}


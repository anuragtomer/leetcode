#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  int countBombs(vector<vector<char>> &board, int x, int y) {
    int count = 0;
    if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M')
      ++count;
    if (x - 1 >= 0 && board[x - 1][y] == 'M')
      ++count;
    if (x - 1 >= 0 && y + 1 < board[x - 1].size() && board[x - 1][y + 1] == 'M')
      ++count;
    if (y - 1 >= 0 && board[x][y - 1] == 'M')
      ++count;
    if (y + 1 < board[x].size() && board[x][y + 1] == 'M')
      ++count;
    if (x + 1 < board.size() && y - 1 >= 0 && board[x + 1][y - 1] == 'M')
      ++count;
    if (x + 1 < board.size() && board[x + 1][y] == 'M')
      ++count;
    if (x + 1 < board.size() && y + 1 < board[x + 1].size() && board[x + 1][y + 1] == 'M')
      ++count;
    return count;
  }
  void bfs(vector<vector<char>> &board, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    board[x][y] = 'B';
    vector<vector<int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int H = board.size(), W = board[0].size();
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for (auto dir : direction) {
        int x = i + dir[0], y = j + dir[1];
        if (x < 0 || y < 0 || x >= H || y >= W || (board[x][y] != 'E' && board[x][y] != 'M'))
          continue;
        int count = countBombs(board, x, y);
        if (count == 0) {
          board[x][y] = 'B';
          q.push({x, y});
        } else
          board[x][y] = '0' + count;
      }
    }
  }

 public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
    int x = click[0], y = click[1];
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
      return board;
    }
    int neighborBombs = countBombs(board, x, y);
    if (neighborBombs == 0) {
      board[x][y] = 'B';
      bfs(board, x, y);
    } else {
      board[x][y] = '0' + neighborBombs;
    }
    return board;
  }
};
int main() {
  Solution sol;

  return 0;
}


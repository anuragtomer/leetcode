#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    for (int r = 0; r < m; ++r)
      for (int c = 0; c < n; ++c)
        if (mat[r][c] == 0)
          q.push({r, c});
        else
          mat[r][c] = -1; // Marked as not processed yet!

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1)
          continue;
        mat[nr][nc] = mat[r][c] + 1;
        q.push({nr, nc});
      }
    }
    return mat;
  }
};

int main() {
  Solution sol;

  return 0;
}


class Solution {
  bool canMove(vector<vector<int>> &grid, int i, int j) {
    if (grid[i][j] == 1) {
      if (j != grid[i].size() - 1) {
        return grid[i][j + 1] != -1;
      } else
        return false;
    } else {
      if (j != 0) {
        return grid[i][j - 1] != 1;
      } else
        return false;
    }
  }

 public:
  vector<int> findBall(vector<vector<int>> &grid) {
    int H = grid.size();
    if (H == 0)
      return {};
    int W = grid[0].size();
    vector<int> result(W, 0);
    iota(result.begin(), result.end(), 0);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (result[j] == -1)
          continue;
        if (canMove(grid, i, result[j])) {
          result[j] += (grid[i][result[j]] == 1 ? 1 : -1);
        } else
          result[j] = -1;
      }
    }
    return result;
  }
};

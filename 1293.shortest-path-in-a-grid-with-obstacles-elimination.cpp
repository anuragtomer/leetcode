class Solution {
  void traverse(vector<vector<int>> &grid, int i, int j, int k, vector<vector<int>> &visited, int steps, const int &H, const int &W) {
    if (visited[i][j] < steps)
      return;
    visited[i][j] = steps;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int it = 0; it < 4; ++it) {
      int x = i + dir[it][0], y = j + dir[it][1];
      if (x < 0 || x >= H || y < 0 || y >= W)
        continue;
      if (grid[x][y] == 1) {
        if (k <= 0)
          continue;
        else
          traverse(grid, x, y, k - 1, visited, steps + 1, H, W);
      } else
        traverse(grid, x, y, k, visited, steps + 1, H, W);
    }
  }
  
  int bfs(vector<vector<int>>& grid, int k) {
    int H = grid.size();
    if (H == 0)
      return 0;
    int W = grid[0].size();
    vector<vector<int>> visited(H, vector<int>(W, -1));
    struct point {
      int i, j, steps, k;
    };
    queue<point> bfsq;

    bfsq.push({0, 0, 0, k});
    while (!bfsq.empty()){
      auto [x, y, steps, k] = bfsq.front();
      bfsq.pop();

      if (x < 0 || y < 0 || x >= H || y >= W) {
        continue;
      }

      if (x == H - 1 && y == W - 1)
        return steps;

      if (grid[x][y] == 1){
        if (k > 0)
          k--;
        else
          continue;
      }

      if (visited[x][y] != -1 && visited[x][y] >= k)
        continue;
      visited[x][y] = k;

      bfsq.push({x + 1, y, steps + 1, k});
      bfsq.push({x, y + 1, steps + 1, k});
      bfsq.push({x - 1, y, steps + 1, k});
      bfsq.push({x, y - 1, steps + 1, k});
    }
    return -1;
  }
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int H = grid.size();
    if (H == 0)
      return 0;
    int W = grid[0].size();
    vector<vector<int>> visited(H, vector<int>(W, -1));
    // traverse(grid, 0, 0, k, visited, 0, H, W);
    return bfs(grid, k);
  }
};

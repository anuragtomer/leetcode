class Solution {
 public:
  int findPaths(int m, int n, int moves, int i, int j,
                vector<vector<vector<int>>> &paths) {
    int MOD = 1e9 + 7;
    if (i < 0 || j < 0 || i >= m || j >= n)
      return 1;
    if (moves == 0)
      return 0;
    if (paths[i][j][moves] >= 0)
      return paths[i][j][moves];
    paths[i][j][moves] = ((findPaths(m, n, moves - 1, i + 1, j, paths) +
                           findPaths(m, n, moves - 1, i, j + 1, paths)) %
                            MOD +
                          (findPaths(m, n, moves - 1, i - 1, j, paths) +
                           findPaths(m, n, moves - 1, i, j - 1, paths)) %
                            MOD) %
                         MOD;
    return paths[i][j][moves];
  }
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> paths(
      m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
    return findPaths(m, n, maxMove, startRow, startColumn, paths);
  }
  /*
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[startRow][startColumn] = 1;
    int MOD = 1e9 + 7;
    int count = 0;
    vector<vector<int>> temp(m, vector<int>(n));
    for (int moves = 1; moves <= maxMove; ++moves) {
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == m - 1)
            count = (count + dp[i][j]) % MOD;
          if (i == 0)
            count = (count + dp[i][j]) % MOD;
          if (j == 0)
            count = (count + dp[i][j]) % MOD;
          if (j == n - 1)
            count = (count + dp[i][j]) % MOD;
          temp[i][j] =
            (((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) %
               MOD +
             ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) %
               MOD) %
            MOD;
        }
      }
      dp = temp;
    }
    return count;
  }
  */
};

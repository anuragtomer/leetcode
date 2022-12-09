class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int elem = 1, i = 0, j = 0, d = 0, row_max = n, col_max = n, row_min = -1,
        col_min = -1;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (elem <= n * n) {
      result[i][j] = elem;
      ++elem;
      i += dir[d][0], j += dir[d][1];
      if (i >= row_max) {
        --i;
        --j;
        --col_max;
        d = (d + 1) % 4;
      } else if (i <= row_min) {
        ++i;
        ++j;
        ++col_min;
        d = (d + 1) % 4;
      }
      if (j >= col_max) {
        --j;
        ++i;
        ++row_min;
        d = (d + 1) % 4;
      } else if (j <= col_min) {
        ++j;
        --i;
        --row_max;
        d = (d + 1) % 4;
      }
    }
    return result;
  }
};

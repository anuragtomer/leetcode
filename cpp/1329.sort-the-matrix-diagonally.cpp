#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int H = mat.size(), W = 0;
    if (H == 0)
      return mat;
    W = mat[0].size();
    for (int j = 0; j < W; ++j) {
      vector<int> diag;
      for (int i = 0, k = j; i < H && k < W; ++i, ++k)
        diag.push_back(mat[i][k]);
      sort(diag.begin(), diag.end());
      auto it = diag.begin();
      for (int i = 0, k = j; i < H && k < W; ++i, ++k, it = next(it))
        mat[i][k] = *it;
    }
    for (int i = 1; i < H; ++i) {
      vector<int> diag;
      for (int j = 0, k = i; j < W && k < H; ++j, ++k)
        diag.push_back(mat[k][j]);
      sort(diag.begin(), diag.end());
      auto it = diag.begin();
      for (int j = 0, k = i; k < H && j < W; ++j, ++k, it = next(it))
        mat[k][j] = *it;
    }
    return mat;
  }
  /* Another Solution */
  vector<vector<int>> diagonalSort2(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        map[i - j].push(mat[i][j]);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        mat[i][j] = map[i - j].top();
        map[i - j].pop();
      }

    return mat;
  }
};

int main() {
  Solution sol;
  auto lmatch = [](vector<vector<int>> &exp, vector<vector<int>> &out) -> bool {
    if (exp.size() != out.size())
      return false;
    for (int i = 0; i < exp.size(); ++i) {
      if (exp[i].size() != out[i].size())
        return false;
      for (int j = 0; j < exp[i].size(); ++j) {
        if (exp[i][j] != out[i][j])
          return false;
      }
    }
    return true;
  };
  vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
  vector<vector<int>> expected = {{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}};
  vector<vector<int>> output = sol.diagonalSort(mat);
  assert(lmatch(expected, output));
  mat = {{11, 25, 66, 1, 69, 7},
         {23, 55, 17, 45, 15, 52},
         {75, 31, 36, 44, 58, 8},
         {22, 27, 33, 25, 68, 4},
         {84, 28, 14, 11, 5, 50}};
  expected = {{5, 17, 4, 1, 52, 7},
              {11, 11, 25, 45, 8, 69},
              {14, 23, 25, 44, 58, 15},
              {22, 27, 31, 36, 50, 66},
              {84, 28, 75, 33, 55, 68}};
  output = sol.diagonalSort(mat);
  assert(lmatch(expected, output));
  return 0;
}

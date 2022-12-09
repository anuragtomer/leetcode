#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    int h = matrix.size() - 1;
    for (int i = 0; i <= h / 2; ++i)
      swap(matrix[i], matrix[h - i]);
    for (int i = 0; i <= h; ++i)
      for (int j = i; j <= h; ++j)
        swap(matrix[i][j], matrix[j][i]);
  }
};

void printMatrix(vector<vector<int>> &matrix) {
  for (auto row : matrix) {
    for (auto val : row)
      cout << val << " ";
    cout << endl;
  }
}
int main() {
  Solution sol;
  auto lmatch = [](vector<vector<int>> &a, vector<vector<int>> &b) -> bool {
    if (a.size() != b.size())
      return false;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i].size() != b[i].size())
        return false;
      for (int j = 0; j < a[i].size(); ++j) {
        if (a[i][j] != b[i][j])
          return false;
      }
    }
    return true;
  };
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  sol.rotate(matrix);
  // printMatrix(matrix);
  vector<vector<int>> expected = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  assert(lmatch(matrix, expected));
  return 0;
}

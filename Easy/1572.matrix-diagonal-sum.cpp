#include <cassert>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int diagonalSum(vector<vector<int>> &mat) {
    int sum = 0, H = mat.size(), W = mat[0].size();
    for (int i = 0, j = 0; i < H && j < W; ++i, ++j)
      sum += mat[i][j];
    for (int i = 0, j = W - 1; i < H && j >= 0; ++i, --j)
      sum += mat[i][j];
    if (H % 2)
      sum -= mat[H / 2][W / 2];
    return sum;
  }
};

int main() {
  Solution sol;
  assert(true);
  return 0;
}

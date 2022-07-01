#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> multiply2(vector<vector<int>> &A, vector<vector<int>> &B) {
    int H1 = A.size(), W1 = A[0].size(), H2 = B.size(), W2 = B[0].size();
    if (W1 != H2)
      return {};
    vector<vector<int>> result(H1, vector<int>(W2, 0));
    for (int i = 0; i < H1; ++i)
      for (int k = 0; k < W1; ++k)
        if (A[i][k] != 0)
          for (int j = 0; j < W2; ++j)
            result[i][j] += (A[i][k] * B[k][j]);

    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}

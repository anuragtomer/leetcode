#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePaths(int W, int H) {
    vector<vector<int>> dp(H, vector<int>(W, 1));
    for (int i = H - 2; i >= 0; --i) {
      for (int j = W - 2; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[0][0];
  }
};

int main() {
  Solution sol;
  assert(28 == sol.uniquePaths(7, 3));
  assert(3 == sol.uniquePaths(3, 2));
  return 0;
}

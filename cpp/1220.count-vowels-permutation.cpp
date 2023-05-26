#include <cassert>
#include <iostream>
using namespace std;

class Solution {
 public:
  /*
  int countVowelPermutation(int n) {
    int MOD = 1e9 + 7;
    vector<vector<int>> dp(2, vector<int>(5, 0));
    dp[0] = {1, 1, 1, 1, 1};
    for (int i = 0; i < n - 1; ++i) {
      // Accounting for which vowel contributes to which
      // vowel.
      dp[(i + 1) % 2][0] =
        ((dp[i % 2][1] + dp[i % 2][2]) % MOD + dp[i % 2][4]) % MOD;
      dp[(i + 1) % 2][1] = (dp[i % 2][0] + dp[i % 2][2]) % MOD;
      dp[(i + 1) % 2][2] = (dp[i % 2][1] + dp[i % 2][3]) % MOD;
      dp[(i + 1) % 2][3] = dp[i % 2][2];
      dp[(i + 1) % 2][4] = (dp[i % 2][2] + dp[i % 2][3]) % MOD;
    }
    return ((dp[(n - 1) % 2][0] + dp[(n - 1) % 2][1]) % MOD +
            ((dp[(n - 1) % 2][2] + dp[(n - 1) % 2][3]) % MOD +
             dp[(n - 1) % 2][4]) %
              MOD) %
           MOD;
  }*/
  int countVowelPermutation(int n) {
    int MOD = 1e9 + 7;
    long a = 1, e = 1, i = 1, o = 1, u = 1;
    long a_, e_, i_, o_, u_;
    for (int j = 2; j <= n; ++j) {
      a_ = (e + i + u) % MOD;
      e_ = (a + i) % MOD;
      i_ = (e + o) % MOD;
      o_ = i % MOD;
      u_ = (i + o) % MOD;
      a = a_, e = e_, i = i_, o = o_, u = u_;
    }
    return ((((a + e) % MOD + i) % MOD + o) % MOD + u) % MOD;
  }
};
int main() {
  Solution sol;
  assert(sol.countVowelPermutation(1) == 5);
  cout << "Pass\n";
  assert(sol.countVowelPermutation(2) == 10);
  cout << "Pass\n";
  assert(sol.countVowelPermutation(3) == 19);
  cout << "Pass\n";
  assert(sol.countVowelPermutation(5) == 68);
  cout << "Pass\n";
}
/*
1:  5
2: 10
3: 19
dp:
-------------
0  1  2  3  4
-------------
1  1  1  1  1: 5
3  2  2  1  2: 10
6  5  3  2  3: 19
11 9  7  3  5: 35
21 18 12 7 10: 68
*/

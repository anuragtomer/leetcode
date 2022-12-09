#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k) {
    int dependency[16] = {0};
    for (auto prereq : dependencies) {
      dependency[prereq[1] - 1] |= (1 << (prereq[0] - 1));
    }
    vector<int> prerequisites(1 << n, 0);
    for (int i = 0; i < (1 << n); ++i) {
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j))
          prerequisites[i] |= dependency[j];
      }
    }
    cout << "Prerequisites: ";
    for (auto prereq : prerequisites)
      cout << prereq << " ";
    cout << endl;
    vector<int> dp(1 << n, n + 1); // start with dp of 2^n elements, each initialized with INT_MAX.
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
      for (int j = i; j != 0; j = (j - 1) & i) {
        if (count_setbit(j) > k)
          continue;
        int already_taken = i ^ ((i << n) - 1);
        if ((already_taken & prerequisites[j]) == prerequisites[j])
          dp[i] = min(dp[i], dp[i ^ j] + 1);
      }
    }
    return dp[(1 << n) - 1];
  }

 private:
  int count_setbit(int mask) {
    if (mask == 0)
      return 0;
    return 1 + count_setbit(mask & (mask - 1));
  }
};

int main() {
  Solution sol;
  int n = 4, k = 2;
  vector<vector<int>> dependencies = {{2, 1}, {3, 1}, {1, 4}};
  assert(3 == sol.minNumberOfSemesters(n, dependencies, k));
  //  n = 5, k = 2;
  //  dependencies = {{2, 1}, {3, 1}, {4, 1}, {1, 5}};
  //  assert(4 == sol.minNumberOfSemesters(n, dependencies, k));
  //  n = 11, k = 2;
  //  dependencies = {};
  //  assert(6 == sol.minNumberOfSemesters(n, dependencies, k));
  return 0;
}
class Solution {
 public:
  // const int N = 16;
  vector<int> adj[16];
  int dp[1 << 16], n, k;

  int solve(int mask) {
    if (mask == (1 << n) - 1) {
      return 0;
    }
    if (dp[mask] != -1) {
      return dp[mask];
    }
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        continue;
      for (auto x : adj[i]) {
        indeg[x]++;
      }
    }
    int tmask = 0;
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0 && !(mask & 1 << i)) {
        tmask |= (1 << i);
      }
    }
    int j = tmask;
    int ans = n + 1;
    int cnt = __builtin_popcount(j);
    if (cnt > k) {
      for (; j; j = (j - 1) & tmask) {
        cnt = __builtin_popcount(j);
        if (cnt != k) {
          continue;
        }
        ans = min(ans, 1 + solve(mask | j));
      }
    } else {
      ans = min(ans, 1 + solve(mask | j));
    }
    return dp[mask] = ans;
  }
  int minNumberOfSemesters(int nn, vector<vector<int>> &d, int kk) {
    n = nn, k = kk;
    for (int i = 0; i < d.size(); i++) {
      d[i][0]--, d[i][1]--;
      adj[d[i][0]].push_back(d[i][1]);
    }
    memset(dp, -1, sizeof(dp));
    return solve(0);
  }
};

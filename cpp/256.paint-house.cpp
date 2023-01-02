#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int helper(vector<vector<int>> &costs, int start_idx, int not_to_be_taken) {
    if (start_idx >= costs.size())
      return 0;
    vector<int> min_costs(3, INT_MAX);
    for (int i = 0; i < 3; ++i) {
      if (i == not_to_be_taken)
        continue;
      min_costs[i] = costs[start_idx][i] + helper(costs, start_idx + 1, i);
    }
    return *min_element(min_costs.begin(), min_costs.end());
  }

 public:
  // timelimit exceeds
  int minCost(vector<vector<int>> costs) { return helper(costs, 0, -1); }
  // works fine. Same logic, no recursion
  int minCost2(vector<vector<int>> costs) {
    int n = costs.size();
    vector<vector<int>> dp(2, vector<int>(3, 0));
    int i = 1;
    for (; i <= n; ++i) {
      dp[i % 2][0] =
        min(dp[(i - 1) % 2][1], dp[(i - 1) % 2][2]) + costs[i - 1][0];
      dp[i % 2][1] =
        min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2]) + costs[i - 1][1];
      dp[i % 2][2] =
        min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]) + costs[i - 1][2];
    }
    return min({dp[(i - 1) % 2][0], dp[(i - 1) % 2][1], dp[(i - 1) % 2][2]});
  }
};

int main() {
  Solution sol;
  assert(10 == sol.minCost({{14, 2, 11}, {11, 14, 5}, {14, 3, 10}}));
  assert(3 == sol.minCost({{1, 2, 3}, {1, 4, 6}}));
  assert(10 == sol.minCost2({{14, 2, 11}, {11, 14, 5}, {14, 3, 10}}));
  assert(3 == sol.minCost2({{1, 2, 3}, {1, 4, 6}}));
  return 0;
}

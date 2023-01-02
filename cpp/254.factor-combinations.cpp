#include <algorithm>
#include <iostream>
#include <vector>

#include "lib.hpp"

using namespace std;

class Solution {
  void dfs(int start, int target, vector<int> &factors,
           vector<vector<int>> &result) {
    if (target <= 1) {
      if (factors.size() > 1) {
        result.push_back(factors);
      }
      return;
    }
    for (int i = start; i <= target; ++i) {
      if (target % i == 0) {
        factors.push_back(i);
        dfs(i, target / i, factors, result);
        factors.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> result;
    vector<int> factors;
    if (n <= 3) {
      return result;
    }
    dfs(2, n, factors, result);
    return result;
  }
};

int main() {
  Solution sol;
  assert(vectors::match_sorted_vecs(sol.getFactors(1), {}));

  assert(vectors::match_sorted_vecs(sol.getFactors(37), {}));
  assert(vectors::match_sorted_vecs(sol.getFactors(12),
                                    {{2, 2, 3}, {2, 6}, {3, 4}}));

  assert(vectors::match_sorted_vecs(
    sol.getFactors(32),
    {{2, 2, 2, 2, 2}, {2, 2, 2, 4}, {2, 2, 8}, {2, 4, 4}, {2, 16}, {4, 8}}));
  return 0;
}

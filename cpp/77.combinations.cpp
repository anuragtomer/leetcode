#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void helper(int n, int k, int i, vector<int> &current, vector<vector<int>> &result) {
    if (k == 0) {
      result.push_back(current);
      return;
    }
    for (; i <= n; ++i) {
      current.push_back(i);
      helper(n, k - 1, i + 1, current, result);
      current.pop_back();
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> current;
    vector<vector<int>> result;
    helper(n, k, 1, current, result);
    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}


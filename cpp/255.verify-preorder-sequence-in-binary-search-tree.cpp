#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  bool helper(vector<int> &preorder, int start, int end, int min_val,
              int max_val) {
    auto find_right = [&]() -> int {
      for (int i = start + 1; i <= end; ++i) {
        if (preorder[i] > preorder[start]) {
          return i;
        }
      }
      return end + 1;
    };
    if (start > end) {
      return true;
    }
    int root_val = preorder[start];
    if (!(root_val > min_val && root_val < max_val)) {
      return false;
    }
    int right_idx = find_right();
    return helper(preorder, start + 1, right_idx - 1, min_val, root_val) &&
           helper(preorder, right_idx, end, root_val, max_val);
  }

 public:
  bool verifyPreorder(vector<int> preorder) {
    if (preorder.empty()) {
      return true;
    }
    return helper(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
  }
};

int main() {
  Solution sol;
  assert(not sol.verifyPreorder({5, 2, 6, 1, 3}));
  assert(sol.verifyPreorder({5, 2, 1, 3, 6}));
  assert(sol.verifyPreorder({1, 3, 2}));
  assert(sol.verifyPreorder({1, 2}));
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> result;
    for (int i = 1, j = n; i <= j;) {
      if (k > 1) {
        result.push_back(k-- % 2 ? i++ : j--);
      } else {
        result.push_back(i++);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  auto lmatch_result = [](vector<int> &a, vector<int> &b) -> bool {
    if (a.size() != b.size())
      return false;
    for (int i = 0; i < a.size(); ++i)
      if (a[i] != b[i])
        return false;
    return true;
  };
  vector<int> output = sol.constructArray(3, 1);
  vector<int> expected = {1, 2, 3};
  assert(lmatch_result(expected, output));
  expected = {3, 1, 2};
  output = sol.constructArray(3, 2);
  assert(lmatch_result(expected, output));
  return 0;
}

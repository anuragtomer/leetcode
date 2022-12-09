#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  bool reorderedPowerOf2(int n) {
    auto count = [](int n) -> vector<int> {
      vector<int> cnt(10, 0);
      while (n) {
        ++cnt[n % 10];
        n /= 10;
      }
      return cnt;
    };
    auto is_same = [](const vector<int> &a, vector<int> b) -> bool {
      for (int i = 0; i < 10; ++i)
        if (a[i] != b[i])
          return false;
      return true;
    };
    const vector<int> &cnt = count(n);
    for (int i = 0; i < 31; ++i)
      if (is_same(cnt, count(1 << i)))
        return true;
    return false;
  }
};

int main() {
  Solution sol;
  assert(sol.reorderedPowerOf2(1));
  assert(not sol.reorderedPowerOf2(10));
  assert(sol.reorderedPowerOf2(61));
  assert(sol.reorderedPowerOf2(125));
  assert(not sol.reorderedPowerOf2(12));
  assert(not sol.reorderedPowerOf2(40));
  return 0;
}

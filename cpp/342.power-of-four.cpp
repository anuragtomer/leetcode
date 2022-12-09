#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int num) {
    if (num < 0)
      return false;
    for (int i = 0; i < 32; ++i)
      if (num == 1 << i)
        return true;
    return false;
  }
};

int main() {
  Solution sol;
  assert(sol.isPowerOfFour(1));
  assert(sol.isPowerOfFour(4));
  assert(sol.isPowerOfFour(16));
  assert(sol.isPowerOfFour(256));
  assert(not sol.isPowerOfFour(5));
  return 0;
}

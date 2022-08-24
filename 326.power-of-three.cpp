#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    while (n != 1) {
      if (n % 3 != 0)
        return false;
      n /= 3;
    }
    return true;
  }
};

int main() {
  Solution sol;
  assert(sol.isPowerOfThree(3));
  assert(sol.isPowerOfThree(1));
  assert(sol.isPowerOfThree(9));
  assert(sol.isPowerOfThree(27));
  assert(not sol.isPowerOfThree(10));
  assert(not sol.isPowerOfThree(30));
  return 0;
}

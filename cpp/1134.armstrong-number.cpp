#include <cassert>
#include <cmath>
using namespace std;

class Solution {
  int find_len(int n) {
    int count = 0;
    while (n) {
      n /= 10;
      ++count;
    }
    return count;
  }

 public:
  bool isArmstrong(int n) {
    int len = find_len(n);
    int orig = n, sum = 0;
    while (n) {
      sum += pow((n % 10), len);
      n /= 10;
    }
    return sum == orig;
  }
};

int main() {
  Solution sol;
  assert(sol.isArmstrong(153));
  assert(not sol.isArmstrong(123));
  return 0;
}

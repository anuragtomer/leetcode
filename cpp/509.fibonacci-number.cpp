#include <cassert>
class Solution {
 public:
  int fib(int n) {
    if (n <= 1)
      return n;
    if (n == 2)
      return 1;
    int minus2 = 1, minus1 = 1, next;
    while (n > 2) {
      --n;
      next = minus1 + minus2;
      minus2 = minus1;
      minus1 = next;
    }
    return minus1;
  }
};

int main() {
  Solution sol;
  assert(sol.fib(1) == 1);
  assert(sol.fib(2) == 1);
  assert(sol.fib(3) == 2);
  assert(sol.fib(4) == 3);
  assert(sol.fib(30) == 832040);
  return 0;
}

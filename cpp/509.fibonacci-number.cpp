class Solution {
 public:
  int fib(int n) {
    if (n == 0)
      return 0;
    int minus2 = 0, minus1 = 1, next = 0;
    --n;
    while (n) {
      next = minus1 + minus2;
      minus2 = minus1;
      minus1 = next;
      --n;
    }
    return minus1;
  }
};

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMinFibonacciNumbers(int k) {
        if (k < 2)
            return k;
        int a = 1, b = 1;
        while (b <= k) {
            swap(a, b);
            b += a;
        }
        return 1 + findMinFibonacciNumbers(k - a);
    }
    /*
    int findMinFibonacciNumbers(int k) {
    array<int, 45> fib;
    int count = 0;
    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i <= 44; ++i) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 44; i >= 0 && k > 0; --i) {
      if (fib[i] <= k) {
        ++count; k -= fib[i];
      }
    }
    return count;
    }
    */
};

int main() {
    Solution sol;

    return 0;
}


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param k: Write your code here
    * @return: the sum of first k even-length palindrome numbers
    */
  int reverse(int i) {
    int rev = 0;
    while (i) {
      rev = rev * 10 + i % 10;
      i = i / 10;
    }
    return rev;
  }
  int sumKEven(int k) {
    int sum = 0, multiplier = 10;
    for (int i = 1; k > 0; ++i, --k) {
      if (i >= multiplier)
        multiplier *= 10;
      int num = i * multiplier + reverse(i);
      sum += num;
    }
    return sum;
  }
};
int main() {
  Solution sol;

  return 0;
}


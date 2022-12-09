#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param n: a number
    * @param d: digit needed to be rorated
    * @return: a number
    */
  int leftRotate(int n, int d) {
    while (d) {
      --d;
      int firstBit = (n >> 31) & 1;
      n = (n << 1) | firstBit;
    }
    return n;
  }
};

int main() {
  Solution sol;

  return 0;
}


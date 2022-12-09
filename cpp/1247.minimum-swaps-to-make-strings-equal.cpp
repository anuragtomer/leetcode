#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    int xy = 0, yx = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == 'x' && s2[i] == 'y')
        ++xy;
      else if (s1[i] == 'y' && s2[i] == 'x')
        ++yx;
    }
    int swaps = xy / 2 + yx / 2;
    xy = xy % 2;
    yx = yx % 2;
    if (xy != yx)
      return -1;
    return swaps + xy + yx;
  }
};

int main() {
  Solution sol;

  return 0;
}


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string convertToTitle(int n) { return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26 + 'A'); }
};

int main() {
  Solution sol;

  return 0;
}


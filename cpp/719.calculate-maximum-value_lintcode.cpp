#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int calcMaxValue(string &str) {
    int result = 0;
    for (auto ch : str) {
      int num = ch - '0';
      if (result * num >= result + num)
        result *= num;
      else
        result += num;
    }
    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}


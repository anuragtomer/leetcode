#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param num: a string
    * @return: true if a number is strobogrammatic or false
    */
  bool isStrobogrammatic(string &num) {
    string mapping = "01xxxx9x86";
    string orig = num;
    reverse(num.begin(), num.end());
    for (auto &ch : orig)
      ch = mapping[ch - '0'];
    return orig == num;
  }
};
int main() {
  Solution sol;

  return 0;
}


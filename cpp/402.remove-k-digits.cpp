#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() <= k) {
      return "0";
    }
    if (k == 0) {
      return num;
    }

    string stackOfDigits;
    for (char ch : num) {
      while (k && not stackOfDigits.empty() && ch < stackOfDigits.back()) {
        --k;
        stackOfDigits.pop_back();
      }
      stackOfDigits.push_back(ch);
      if (stackOfDigits.size() == 1 && stackOfDigits.back() == '0') {
        stackOfDigits.pop_back();
      }
    }
    while (k > 0 && not stackOfDigits.empty()) {
      stackOfDigits.pop_back();
      --k;
    }
    return stackOfDigits.empty() ? "0" : stackOfDigits;
  }
};

int main() {
  Solution sol;
  string num = "1432219";
  int k = 3;
  assert("1219" == sol.removeKdigits(num, k));
  num = "10200", k = 1;
  assert("200" == sol.removeKdigits(num, k));
  num = "10", k = 2;
  assert("0" == sol.removeKdigits(num, k));
  return 0;
}

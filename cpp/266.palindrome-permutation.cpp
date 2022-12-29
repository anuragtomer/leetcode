#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canPermutePalindrome(string s) {
    bitset<256> chars;
    for (auto &ch : s) {
      chars.flip(ch);
    }
    return chars.count() <= 1;
  }
};
int main() {
  Solution sol;
  assert(not sol.canPermutePalindrome("code"));
  cout << "Pass 1" << endl;
  assert(sol.canPermutePalindrome("aab"));
  cout << "Pass 2" << endl;
  assert(sol.canPermutePalindrome("carerac"));
  cout << "Pass 3" << endl;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include <bitset>
class Solution {
 public:
  /**
    * @param s: the given string
    * @return: if a permutation of the string could form a palindrome
    */
  bool canPermutePalindrome(string &s) {
    bitset<256> btst;
    for (auto &ch : s) {
      btst.flip(ch);
    }
    return (btst.count() <= 1);
  }
};
int main() {
  Solution sol;

  return 0;
}


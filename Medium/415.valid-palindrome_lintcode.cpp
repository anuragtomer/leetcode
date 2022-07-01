#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param s: A string
    * @return: Whether the string is a valid palindrome
    */
  bool alpha(char ch) { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'); }
  char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z')
      return ch + 32;
    return ch;
  }
  bool isPalindrome(string &s) {
    for (int left = 0, right = s.size() - 1; left < right;) {
      if (!alpha(s[left]))
        ++left;
      else if (!alpha(s[right]))
        --right;
      else if (toLower(s[left]) == toLower(s[right])) {
        ++left;
        --right;
      } else
        return false;
    }
    return true;
  }
};

int main() {
  Solution sol;

  return 0;
}


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param s: the article
    * @return: the number of letters that are illegal
    */
  int count(string &s) {
    // Write your code here.
    bool caps = true;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (caps && s[i] >= 'a' && s[i] <= 'z')
        ans++;
      if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        caps = false; // Next must not be caps
      if (s[i] == '.')
        caps = true; // Next must be caps
      if (i > 0 && (s[i - 1] >= 'a' && s[i - 1] <= 'z' || s[i - 1] >= 'A' && s[i - 1] <= 'Z') && s[i] >= 'A' &&
          s[i] <= 'Z') {
        ans++;
        // last was a character, current is Caps chars, Invalid.
      }
    }
    return ans;
  }
};
int main() {
  Solution sol;

  return 0;
}


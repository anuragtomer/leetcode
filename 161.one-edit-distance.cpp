#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param s: a string
    * @param t: a string
    * @return: true if they are both one edit distance apart or false
    */
  bool isOneEditDistance(string &s, string &t) {
    int m = s.size(), n = t.size();
    if (abs(n - m) > 1)
      return false;
    bool oneEdit = false;
    for (int i = 0, j = 0; i < m || j < n;) {
      if (i < m && j < n && s[i] == t[j]) {
        ++i, ++j;
      } else {
        if (oneEdit == true)
          return false;
        oneEdit = true;
        if (m == n) {
          ++i, ++j;
        } else if (m < n)
          ++j;
        else
          ++i;
      }
    }
    return oneEdit;
  }
};
int main() {
  Solution sol;

  return 0;
}


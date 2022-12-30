#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    int n = s.size(), m = t.size();
    if (n > m + 1 || m > n + 1) {
      return false;
    }
    bool one_edit = false;
    for (int i = 0, j = 0; i < n || j < m;) {
      if (i < n && j < m && s[i] == t[j]) {
        ++i;
        ++j;
      } else {
        if (one_edit) {
          return false;
        }
        one_edit = true;
        if (n < m) {
          ++j;
        } else if (m < n) {
          ++i;
        } else {
          ++i;
          ++j;
        }
      }
    }
    return one_edit || abs(n - m) == 1;
  }
};

int main() {
  Solution sol;
  assert(sol.isOneEditDistance("ab", "acb"));
  assert(sol.isOneEditDistance("a", "ab"));
  assert(sol.isOneEditDistance("abcde", "bcde"));
  assert(not sol.isOneEditDistance("ax", "acb"));
  assert(not sol.isOneEditDistance("ab", "ab"));
  assert(not sol.isOneEditDistance("cab", "ad"));
  assert(sol.isOneEditDistance("1203", "1213"));
  cout << "Pass";
  return 0;
}

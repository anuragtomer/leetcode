#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    int currentCost = 0, maxLen = 0;
    for (int j = 0, i = 0; i < s.size(); ++i) {
      currentCost += abs(s[i] - t[i]);
      while (currentCost > maxCost && j <= i) {
        currentCost -= abs(s[j] - t[j]);
        ++j;
      }
      maxLen = max(maxLen, i - j + 1);
    }
    return maxLen;
  }
};

int main() {
  Solution sol;

  return 0;
}


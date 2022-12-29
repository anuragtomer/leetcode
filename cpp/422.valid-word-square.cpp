#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validWordSquare(vector<string> words) {
    for (int i = 0, n = words.size(); i < n; ++i) {
      if (words[i].size() != n) {
        return false;
      }
      for (int j = i + 1; j < n; ++j) {
        if (words[i][j] != words[j][i]) {
          return false;
        }
      }
    }
    return true;
  }
};
int main() {
  Solution sol;
  assert(sol.validWordSquare({"abcd", "bnrt", "crmy", "dtye"}));
  assert(not sol.validWordSquare({"abcd", "bnrt", "crm", "dt"}));
  assert(not sol.validWordSquare({"ball", "area", "read", "lady"}));
  return 0;
}

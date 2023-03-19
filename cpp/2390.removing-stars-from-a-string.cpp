#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeStars(string s) {
    string result;
    for (auto ch : s) {
      if (ch == '*')
        result.pop_back();
      else
        result.push_back(ch);
    }
    return result;
  }
};
int main() {
  Solution sol;
  string s = "leet**cod*e";
  string out = "lecoe";
  assert(out == sol.removeStars(s));
  s = "erase*****";
  out = "";
  assert(out == sol.removeStars(s));
  return 0;
}

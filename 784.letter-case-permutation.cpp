#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void helper(string s, int i, vector<string> &result, string &current) {
    if (i == s.size()) {
      result.push_back(current);
      return;
    }
    if (s[i] >= '0' && s[i] <= '9') {
      current.push_back(s[i]);
      helper(s, i + 1, result, current);
      current.pop_back();
    } else {
      current.push_back(s[i]);
      helper(s, i + 1, result, current);
      current.pop_back();
      if (s[i] >= 'a' && s[i] <= 'z')
        current.push_back(s[i] - 32);
      else
        current.push_back(s[i] + 32);
      helper(s, i + 1, result, current);
      current.pop_back();
    }
  }

 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> result;
    string current;
    helper(s, 0, result, current);
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}


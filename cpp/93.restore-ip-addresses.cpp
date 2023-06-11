#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
  bool isValid(string str) {
    if (str.empty() || str.size() > 3)
      return false;
    if (str.size() > 1 && str[0] == '0')
      return false;
    if (not str.empty() && stoi(str) >= 256)
      return false;
    return true;
  }

  void helper(string s, int dots, int idx, vector<string> &result,
              string current) {
    if (dots == 3) {
      if (isValid(s.substr(idx))) {
        result.push_back(current + s.substr(idx));
      }
      return;
    }
    if (dots > 3)
      return;
    for (int i = idx, sz = s.size(); i < min(idx + 3, sz); ++i) {
      if (isValid(s.substr(idx, i - idx + 1))) {
        current.push_back(s[i]);
        current.push_back('.');
        helper(s, dots + 1, i + 1, result, current);
        current.pop_back();
      }
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string current;
    helper(s, 0, 0, result, current);
    return result;
  }
};
int main() {
  auto lMatch = [](vector<string> out, vector<string> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    sort(out.begin(), out.end());
    sort(exp.begin(), exp.end());
    for (int i = 0; i < out.size(); ++i) {
      if (out[i] != exp[i])
        return false;
    }
    return true;
  };
  Solution sol;
  string s = "25525511135";
  vector<string> expected = {"255.255.11.135", "255.255.111.35"};
  assert(lMatch(sol.restoreIpAddresses(s), expected));
  s = "0000";
  expected = {"0.0.0.0"};
  assert(lMatch(sol.restoreIpAddresses(s), expected));
  s = "101023";
  expected = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
  assert(lMatch(sol.restoreIpAddresses(s), expected));
  return 0;
}


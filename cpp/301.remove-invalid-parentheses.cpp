#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  void helper(string &s, unique_ptr<unordered_set<string>> &result,
              string &current, int extra_open, int extra_close,
              int unmatched_open, int i) {
    if (i == s.size()) {
      if (extra_open == 0 && extra_close == 0 && unmatched_open == 0) {
        result->insert(current);
      }
      return;
    }
    if (s[i] == '(') {
      // Either this open brace starts a new group that would be closed later on.
      // So add it to current and try to create a valid string.
      current.push_back(s[i]);
      helper(s, result, current, extra_open, extra_close, unmatched_open + 1,
             i + 1);
      current.pop_back();
      if (extra_open > 0) {
        // Or this was one of the extra open bracket that we had. So ignore it.
        helper(s, result, current, extra_open - 1, extra_close, unmatched_open,
               i + 1);
      }
    } else if (s[i] == ')') {
      if (unmatched_open > 0) {
        // I have some unmatched open brackets. Lets match this current close
        // bracket with earlier open bracket.
        current.push_back(s[i]);
        helper(s, result, current, extra_open, extra_close, unmatched_open - 1,
               i + 1);
        current.pop_back();
      }
      if (extra_close > 0) {
        // May be this was an extra close bracket. Ignore it
        helper(s, result, current, extra_open, extra_close - 1, unmatched_open,
               i + 1);
      }
    } else {
      // Its not either bracket. Add and move forward.
      current.push_back(s[i]);
      helper(s, result, current, extra_open, extra_close, unmatched_open,
             i + 1);
      current.pop_back();
    }
  }

 public:
  vector<string> removeInvalidParentheses(string s) {
    unique_ptr<unordered_set<string>> result =
      make_unique<unordered_set<string>>();
    int extra_open = 0, extra_close = 0, unmatched_open = 0;
    for (auto ch : s) {
      if (ch == '(')
        ++extra_open;
      else if (ch == ')') {
        if (extra_open > 0)
          --extra_open;
        else
          ++extra_close;
      }
    }
    string current;
    helper(s, result, current, extra_open, extra_close, unmatched_open, 0);
    return vector<string>(result->begin(), result->end());
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
  vector<string> expected;
  expected = {"(())()", "()()()"};
  assert(lMatch(sol.removeInvalidParentheses("()())()"), expected));
  expected = {"(a())()", "(a)()()"};
  assert(lMatch(sol.removeInvalidParentheses("(a)())()"), expected));
  expected = {""};
  assert(lMatch(sol.removeInvalidParentheses(")("), expected));
  return 0;
}


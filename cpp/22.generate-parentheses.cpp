/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  void helper(int n, int openCount, string &current, vector<string> &result) {
    if (openCount == 0 && n == 0) {
      result.push_back(current);
      return;
    }
    if (n > 0) {
      current.push_back('(');
      helper(n - 1, openCount + 1, current, result);
      current.pop_back();
    }
    if (openCount > 0) {
      current.push_back(')');
      helper(n, openCount - 1, current, result);
      current.pop_back();
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    int openCount = 0;
    vector<string> result;
    string current;
    helper(n, openCount, current, result);
    return result;
  }
}; // @lc code=end

int main() {
  int n;
  Solution sol;
  vector<string> expected = {"((()))", "(()())", "(())()", "()(())", "()()()"};
  vector<string> output = sol.generateParenthesis(3);
  assert(expected.size() == output.size());
  sort(expected.begin(), expected.end());
  sort(output.begin(), output.end());
  for (int i = 0; i < expected.size(); ++i) {
    assert(expected[i] == output[i]);
  }
  cout << "Pass 1 \n";
  return 0;
}

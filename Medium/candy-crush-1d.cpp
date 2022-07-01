#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  string candyCrush(string str) {
    stack<pair<char, int>> chars;
    for (int i = 0, n = str.size(); i < n; ++i) {
      if (chars.empty())
        chars.push({str[i], 1});
      else if (chars.top().first != str[i]) {
        if (chars.top().second >= 3) {
          chars.pop();
          if (chars.empty() == false && chars.top().first == str[i])
            chars.top().second++;
          else
            chars.push({str[i], 1});
        } else
          chars.push({str[i], 1});
      } else {
        chars.top().second++;
      }
    }
    string result;
    while (chars.empty() == false) {
      auto topElement = chars.top();
      chars.pop();
      while (chars.empty() == false && chars.top().first == topElement.first) {
        topElement.second += chars.top().second;
        chars.pop();
      }
      if (topElement.second <= 2)
        result.append(string(topElement.second, topElement.first));
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;
  assert("c" == sol.candyCrush("aaabbbc"));
  assert("cd" == sol.candyCrush("aabbbacd"));
  assert("" == sol.candyCrush("aabbccddeeedcba"));
  assert("acd" == sol.candyCrush("aaabbbacd"));
  return 0;
}


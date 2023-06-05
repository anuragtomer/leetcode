#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  bool isNum(char ch) { return ch >= '0' && ch <= '9'; }
  bool isChar(char ch) { return ch >= 'a' && ch <= 'z'; }
  int getInt(string s, int &i, const int &n) {
    int num = 0;
    while (i < n && isNum(s[i])) {
      num = num * 10 + (s[i] - '0');
      ++i;
    }
    --i;
    return num;
  }

 public:
  string decodeString(string s) {
    stack<string> str_stack;
    stack<int> num_stack;
    string decoded;
    int i = 0, n = s.size();
    while (i < n) {
      if (isNum(s[i])) {
        num_stack.push(getInt(s, i, n));
      } else if (isChar(s[i])) {
        decoded.push_back(s[i]);
      } else if (s[i] == '[') {
        str_stack.push(decoded);
        decoded.clear();
      } else if (s[i] == ']') {
        string last_str = str_stack.top();
        str_stack.pop();
        int repeat_count = num_stack.top();
        num_stack.pop();
        while (repeat_count) {
          last_str.append(decoded);
          --repeat_count;
        }
        decoded = last_str;
        last_str.clear();
      }
      ++i;
    }
    return decoded;
  }
};

int main() {
  Solution sol;
  assert(sol.decodeString("3[a]2[bc]") == "aaabcbc");
  assert(sol.decodeString("3[a2[c]]") == "accaccacc");
  assert(sol.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
  return 0;
}

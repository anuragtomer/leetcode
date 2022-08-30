#include <cassert>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    unordered_map<string, function<int(int, int)>> map = {
      {"+", [](int a, int b) { return a + b; }},
      {"-", [](int a, int b) { return a - b; }},
      {"*", [](int a, int b) { return a * b; }},
      {"/", [](int a, int b) { return a / b; }}};
    stack<int> stack;
    for (string &s : tokens) {
      if (!map.count(s)) {
        stack.push(stoi(s));
      } else {
        int op1 = stack.top();
        stack.pop();
        int op2 = stack.top();
        stack.pop();
        stack.push(map[s](op2, op1));
      }
    }
    return stack.top();
  }
};

int main() {
  Solution sol;
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  assert(9 == sol.evalRPN(tokens));
  tokens = {"4", "13", "5", "/", "+"};
  assert(6 == sol.evalRPN(tokens));
  tokens = {"10", "6", "9",  "3", "+", "-11", "*",
            "/",  "*", "17", "+", "5", "+"};
  assert(22 == sol.evalRPN(tokens));
  tokens = {"3", "-4", "+"};
  assert(-1 == sol.evalRPN(tokens));
  tokens = {"4", "3", "-"};
  assert(1 == sol.evalRPN(tokens));
  return 0;
}


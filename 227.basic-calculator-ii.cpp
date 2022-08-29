#include <stack>
#include <string>
using namespace std;
class Solution {
 public:
  int calculate(string s) {
    stack<int> st;
    char sign = '+';
    long res = 0, tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
      if (isdigit(s[i]))
        tmp = 10 * tmp + s[i] - '0';
      if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
        if (sign == '-')
          st.push(-tmp);
        else if (sign == '+')
          st.push(tmp);
        else {
          int num = st.top();
          st.pop();
          if (sign == '*')
            num *= tmp;
          else
            num /= tmp;
          st.push(num);
        }
        sign = s[i];
        tmp = 0;
      }
    }
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }
    return res;
  }
};
int main() {
  Solution sol;
  assert(7 == sol.calculate("3+9/2"));
  assert(7 == sol.calculate("3+2*2"));
  assert(1 == sol.calculate(" 3/2 "));
  assert(5 == sol.calculate(" 3+5 / 2 "));
  return 0;
}

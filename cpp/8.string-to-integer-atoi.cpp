#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int my_atoi(string s) {
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') // Ignore spaces
      ++i;
    if (i >= n)
      return 0;
    int num = 0;
    bool negative = false;
    if (s[i] == '-') { // See if num should be negative;
      negative = true;
      ++i;
    } else if (s[i] == '+') {
      ++i;
    }
    while (i < n && (s[i] >= '0' && s[i] <= '9')) {
      if ((INT_MAX - s[i] + '0') / 10 >= num) {
        num = (num * 10) + (s[i] - '0');
        ++i;
      } else {
        return negative ? INT_MIN : INT_MAX;
      }
    }
    return negative ? -1 * num : num;
  }
};

int main() {
  Solution sol;
  assert(42 == sol.my_atoi("42"));
  assert(-42 == sol.my_atoi("    -42"));
  assert(sol.my_atoi("4193 with words") == 4193);
  assert(sol.my_atoi("     ") == 0);
  assert(sol.my_atoi("words and 987") == 0);
  assert(sol.my_atoi("2147483649") == 2147483647);
  assert(sol.my_atoi("-91283472332") == -2147483648);
  assert(sol.my_atoi("  +99") == 99);
  return 0;
}

#include <iostream>
using namespace std;

class Solution {
  void normalize(string &str) {
    int j = -1;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] != '#') {
        str[++j] = str[i];
      } else {
        if (j >= 0)
          --j;
      }
    }
    str.resize(j + 1);
  }

 public:
  bool backspaceCompare(string s, string t) {
    normalize(s);
    normalize(t);
    return s == t;
  }
};
int main() {
  Solution sol;
  string S{"a#b#c#######abc#"};
  string T{"abc###abc#"};
  cout << boolalpha << sol.backspaceCompare(S, T);
  return 0;
}

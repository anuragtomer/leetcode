#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string freqAlphabets(string s) {
    string result;
    for (int i = s.size() - 1; i >= 0;) {
      if (s[i] == '#') {
        int num = (s[i - 1] - '0') + 10 * (s[i - 2] - '0');
        result.push_back('a' + num - 1);
        i -= 3;
      } else {
        result.push_back(s[i] - '0' + 'a' - 1);
        --i;
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}


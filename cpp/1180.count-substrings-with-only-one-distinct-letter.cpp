#include <string>

using namespace std;

class Solution {
 public:
  int countLetters(string s) {
    int count = 1, total_count = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] != s[i]) {
        total_count += (count * (count + 1)) / 2;
        count = 1;
      } else {
        ++count;
      }
    }
    return total_count + (count * (count + 1)) / 2;
  }
};

int main() {
  Solution sol;
  assert(sol.countLetters("aaaaaaaaaa") == 55);
  assert(sol.countLetters("aaabc") == 8);
  return 0;
}

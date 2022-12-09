#include <bitset>
#include <string>

using namespace std;

class Solution {
 public:
  int partitionString(string s) {
    bitset<256> charCount;
    int substrs = 1;
    for (auto ch : s) {
      if (charCount.test(ch)) {
        ++substrs;
        charCount.reset();
      }
      charCount.set(ch);
    }
    return substrs;
  }
};
int main() {
  Solution sol;
  assert(sol.partitionString("abacaba") == 4);
  assert(sol.partitionString("ssssss") == 6);
  assert(sol.partitionString("hdklqkcssgxlvehva") == 4);
  return 0;
}


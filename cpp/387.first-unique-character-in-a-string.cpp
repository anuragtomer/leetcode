#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> hash;
    for (auto &ch : s) {
      hash[ch]++;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (hash[s[i]] == 1)
        return i;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  assert(0 == sol.firstUniqChar("leetcode"));
  assert(2 == sol.firstUniqChar("loveleetcode"));
  assert(-1 == sol.firstUniqChar("aabb"));
  return 0;
}

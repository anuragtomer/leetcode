#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int count[26];
    memset(count, 0, sizeof(int) * 26);
    int noteChars = ransomNote.size();
    for (auto &ch : ransomNote)
      count[ch - 'a']++;
    for (auto &ch : magazine) {
      count[ch - 'a']--;
      if (count[ch - 'a'] >= 0)
        --noteChars;
      if (noteChars == 0)
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol;

  return 0;
}


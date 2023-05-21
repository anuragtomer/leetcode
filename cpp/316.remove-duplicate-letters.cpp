#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> count(256, 0);
    for (auto ch : s)
      count[ch]++;
    string result;
    unordered_set<char> inserted_chars;
    for (auto ch : s) {
      /*
       * If last character of current string is greater than incoming character
       * AND
       * there are more of last character that can be picked later
       * AND
       * I've not yet inserted this incoming character in result string.
       * THEN
       * remove last character from result string and remove it from inserted
       * set.
       **/
      while (!result.empty() && result.back() >= ch &&
             count[result.back()] > 0 && inserted_chars.count(ch) == 0) {
        inserted_chars.erase(inserted_chars.find(result.back()));
        result.pop_back();
      }
      if (inserted_chars.count(ch) == 0) {
        result.push_back(ch);
        inserted_chars.insert(ch);
      }
      --count[ch];
    }
    return result;
  }
};

int main() {
  Solution sol;
  cout << "Testcase 1\n";
  assert(sol.removeDuplicateLetters("bcabc") == "abc");
  cout << "Testcase 2\n";
  assert(sol.removeDuplicateLetters("cbacdcbc") == "acdb");
  cout << "All test cases passed\n";
  return 0;
}

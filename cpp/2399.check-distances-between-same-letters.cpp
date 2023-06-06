#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkDistances(string s, vector<int> &distance) {
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];
      if (distance[ch - 'a'] != 0) {
        int dist = distance[ch - 'a'] + 1;
        if (i - dist >= 0 && s[i - dist] == ch)
          ; // This character is dist places behind
        else if (i + dist < s.size() && s[i + dist] == ch)
          ; // This character is dist places ahead
        else
          return false; // This is nowhere to be found
      }
    }
    return true;
  }
};
int main() {
  Solution sol;
  vector<int> distance = {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  assert(sol.checkDistances("abaccb", distance));
  distance = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  assert(not sol.checkDistances("aa", distance));
  cout << "All test cases passed.";
  return 0;
}
